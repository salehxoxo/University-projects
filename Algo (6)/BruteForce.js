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

    for (var i = 0; i < n; i++) {
        var x = Math.floor(Math.random() * width);
        var y = Math.floor(Math.random() * height);
        points.push({x: x, y: y});

        // Create SVG element for the point and append it to the SVG container
        var point = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
        point.setAttribute('cx', x);
        point.setAttribute('cy', y);
        point.setAttribute('r', 5);
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

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function drawLine(line, svgLines, color = 'black') {
    if (!line.leftmost || !line.rightmost) {
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

function removeBlackLines(svg) {
    var blackLines = svg.querySelectorAll('line[stroke="black"]');
    blackLines.forEach(function(line) {
        svg.removeChild(line);
    });
}


async function BruteForce(n) {
    var points = generatePoints(n);
    var hull = [];
    var svg = document.querySelector('#svg');

    for (var i = 0; i < points.length; i++) {
        for (var j = i + 1; j < points.length; j++) {
            var x1 = points[i].x, y1 = points[i].y;
            var x2 = points[j].x, y2 = points[j].y;

            var isLeft = false, isRight = false;

            // Draw a black line between the points being compared
            drawLine({leftmost: points[i], rightmost: points[j]}, svg, 'black');

            await sleep(1000);  // Wait for 1 second

            for (var k = 0; k < points.length; k++) {
                if (k != i && k != j) {
                    var x3 = points[k].x, y3 = points[k].y;
                    var det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
                    if (det < 0) {
                        isLeft = true;
                    } else if (det > 0) {
                        isRight = true;
                    }
                }
            }

            if (isLeft != isRight) {
                if (!hull.includes(points[i])) {
                    hull.push(points[i]);
                }
                if (!hull.includes(points[j])) {
                    hull.push(points[j]);
                }

                // Draw a green line between the points added to the hull
                drawLine({leftmost: points[i], rightmost: points[j]}, svg, 'green');
            }
        }
    }

    // Remove duplicate points from the hull
    hull = Array.from(new Set(hull.map(JSON.stringify))).map(JSON.parse);
    console.log(hull);
     // Remove all black lines
     removeBlackLines(svg);
}

