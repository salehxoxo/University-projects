// Function to pause execution
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function generatePoints(n) {
    var points = [];
    var canvas = document.querySelector('#canvas');
    var width = canvas.offsetWidth;
    var height = canvas.offsetHeight;

    // Create SVG container
    var svg = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
    svg.setAttribute('id', 'svg');
    svg.setAttribute('width', width);
    svg.setAttribute('height', height);
    canvas.appendChild(svg);

    // Define a padding to prevent points from being on the edge of the canvas
    var padding = 10;

    for (var i = 0; i < n; i++) {
        var x = Math.floor(Math.random() * (width - 2 * padding) + padding);
        var y = Math.floor(Math.random() * (height - 2 * padding) + padding);
        points.push({x: x, y: y});

        // Create SVG element for the point and append it to the SVG container
        var point = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
        point.setAttribute('cx', x);
        point.setAttribute('cy', y);
        point.setAttribute('r', 6);
        point.setAttribute('fill', 'red');
        point.setAttribute('id', `point${i}`);

        // Add title element with coordinates
        var title = document.createElementNS('http://www.w3.org/2000/svg', 'title');
        title.textContent = `(${x}, ${y})`;
        point.appendChild(title);

        svg.appendChild(point);
    }

    return points;
}

function drawLine(line, svgLines, color = 'black') {
    if (!line.leftmost || !line.rightmost || !('x' in line.leftmost && 'y' in line.leftmost && 'x' in line.rightmost && 'y' in line.rightmost)) {
        console.error('Invalid line:', line);
        return;
    }

    var lineElement = document.createElementNS('http://www.w3.org/2000/svg', 'line');
    lineElement.setAttribute('x1', line.leftmost.x);
    lineElement.setAttribute('y1', line.leftmost.y);
    lineElement.setAttribute('x2', line.rightmost.x);
    lineElement.setAttribute('y2', line.rightmost.y);
    lineElement.setAttribute('stroke', color);
    lineElement.setAttribute('stroke-width', 2);
    svgLines.appendChild(lineElement);
}

function orientation(p, q, r) {
    var val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counterclockwise
}

function distSq(p1, p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

function nextToTop(stack) {
    return stack[stack.length - 2];
}

function drawHull(hull, svg) {
    // Now stack has the output points, print contents of stack
    for (var i = 0; i < hull.length - 1; i++) {
        drawLine({leftmost: hull[i], rightmost: hull[i + 1]}, svg, 'green');
    }
    // Draw a line between the last point and the first point
    drawLine({leftmost: hull[hull.length - 1], rightmost: hull[0]}, svg, 'green');
}

async function grahamScan(n) {
    var points = generatePoints(n);
    var svg = document.querySelector('#svg');

    // Find the bottommost point
    var ymin = points[0].y, min = 0;
    for (var i = 1; i < points.length; i++) {
        var y = points[i].y;

        // Pick the bottom-most or chose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y, min = i;
        }
    }

    // Change the color of the selected point to yellow
    var selectedPointElement = document.querySelector(`#point${min}`);
    selectedPointElement.setAttribute('fill', 'blue');

    // Place the bottom-most point at first position
    var temp = points[0];
    points[0] = points[min];
    points[min] = temp;

    // Sort n-1 points with respect to the first point.
    var p0 = points[0];
    points.sort(function(p1, p2) {
        // Calculate the angle between p0p1 and p0p2
        var angle1 = Math.atan2(p1.y - p0.y, p1.x - p0.x);
        var angle2 = Math.atan2(p2.y - p0.y, p2.x - p0.x);

        // Subtract the angles to get the relative angle from p1 to p2
        var relativeAngle = angle1 - angle2;

        // If the points are collinear with p0, sort them by distance to p0
        if (relativeAngle === 0) {
            return distSq(p0, p2) >= distSq(p0, p1) ? -1 : 1;
        }

        // Otherwise, sort them by the relative angle
        return relativeAngle;
    });

    // Label the points as p0, p1, ..., pn-1 and display the labels
    for (var i = 0; i < points.length; i++) {
        points[i].label = `p${i}`;

        // Create SVG element for the label and append it to the SVG container
        var label = document.createElementNS('http://www.w3.org/2000/svg', 'text');
        label.setAttribute('x', points[i].x);
        label.setAttribute('y', points[i].y + 15);  // Position the label below the point
        label.setAttribute('fill', 'black');
        label.textContent = `p${i}`;
        svg.appendChild(label);
    }

    // Draw dotted lines from the selected point to each other point
    for (var i = 1; i < points.length; i++) {
        var line = document.createElementNS('http://www.w3.org/2000/svg', 'line');
        line.setAttribute('x1', points[0].x);
        line.setAttribute('y1', points[0].y);
        line.setAttribute('x2', points[i].x);
        line.setAttribute('y2', points[i].y);
        line.setAttribute('stroke', 'black');
        line.setAttribute('stroke-dasharray', '4');
        line.setAttribute('id', `line${points[i].label.substring(1)}`);  // Assign a unique ID to the line
        svg.appendChild(line);
    }

    // Create an empty stack and push first three points to it.
    var stack = [];
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);

    // Process remaining n-3 points
    for (var i = 3; i < points.length; i++) {
        await sleep(1000);
        // Change the color of the points being compared to black
        var pointElement1 = document.querySelector(`#point${stack[stack.length - 1].label.substring(1)}`);
        var pointElement2 = document.querySelector(`#point${points[i].label.substring(1)}`);
        pointElement1.setAttribute('fill', 'black');
        pointElement2.setAttribute('fill', 'black');

        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (stack.length > 1 && orientation(nextToTop(stack), stack[stack.length - 1], points[i]) != 2) {
            // Change the color of the point being removed to red
            var removedPointElement = document.querySelector(`#point${stack[stack.length - 1].label.substring(1)}`);
            removedPointElement.setAttribute('fill', 'red');

            // Change the color of the line associated with the point being removed to black
            var removedLineElement = document.querySelector(`#line${stack[stack.length - 1].label.substring(1)}`);
            removedLineElement.setAttribute('stroke', 'black');
            removedLineElement.setAttribute('stroke-dasharray', '4');  // Make the line dotted again

            stack.pop();
        }

        // Change the color of the point being added to red
        var addedPointElement = document.querySelector(`#point${points[i].label.substring(1)}`);
        addedPointElement.setAttribute('fill', 'red');

        // Change the color of the line associated with the point being added to red and make it solid
        var addedLineElement = document.querySelector(`#line${points[i].label.substring(1)}`);
        addedLineElement.setAttribute('stroke', 'red');
        addedLineElement.setAttribute('stroke-dasharray', '1');  // Make the line solid

        stack.push(points[i]);
    }

    console.log(stack);
    drawHull(stack, svg);
}


