// Function to generate random points within the canvas range
function generateRandomPoints(numPoints) {
    const canvas = document.getElementById('canvas');
    const points = [];
    const canvasRect = canvas.getBoundingClientRect();
    const maxX = canvasRect.width - 10; // Adjusted for padding
    const maxY = canvasRect.height - 10; // Adjusted for padding
  
    for (let i = 0; i < numPoints; i++) {
      const x = Math.floor(Math.random() * maxX);
      const y = Math.floor(Math.random() * maxY);
      points.push({ x, y });
    }
  
    return points;
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function drawPointSVG(svgContainer, x, y) {
    const svgPoint = document.createElementNS("http://www.w3.org/2000/svg", "circle");
    svgPoint.setAttribute("cx", x);
    svgPoint.setAttribute("cy", y);
    svgPoint.setAttribute("r", 5); // Adjust radius as needed
    svgPoint.setAttribute("fill", "red"); // Set point color
    svgContainer.appendChild(svgPoint);
}

function drawLineSVG(svgContainer, x1, y1, x2, y2, color = '#00000') {
    console.log(`Line coordinates: (${x1}, ${y1}), (${x2}, ${y2})`);
    const svgLine = document.createElementNS("http://www.w3.org/2000/svg", "line");
    svgLine.setAttribute("x1", x1);
    svgLine.setAttribute("y1", y1);
    svgLine.setAttribute("x2", x2);
    svgLine.setAttribute("y2", y2);
    svgLine.setAttribute("stroke", color); // Set line color
    svgLine.setAttribute("stroke-width", 2); // Adjust line width as needed
    svgContainer.appendChild(svgLine);
}


 // Function to check if the next point makes a clockwise turn
 function isClockwiseTurn(p1, p2, p3) {
    const crossProduct = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
    return crossProduct < 0;
}

// Function to compute the convex hull using Kirkpatrick-Seidel Algorithm with visualization
async function DivideNconquer(points, svgCanvas) {
    // Sort points based on x-coordinate
    points.sort((a, b) => a.x - b.x);

    const upperHull = [];
    const lowerHull = [];
  
    // Find the upper hull and visualize
    for (let i = 0; i < points.length; i++) { 
        await sleep(1000);  
        while (upperHull.length >= 2 && isClockwiseTurn(
            upperHull[upperHull.length - 2],
            upperHull[upperHull.length - 1],
            points[i]
        )) {
            upperHull.pop();
        }
        upperHull.push(points[i]);
        // Call drawPointSVG to visualize the points
        drawPointSVG(svgCanvas, points[i].x, points[i].y);
        // Visualize upper hull lines
        if (upperHull.length >= 2) {
            drawLineSVG(
                svgCanvas,
                upperHull[upperHull.length - 2].x,
                upperHull[upperHull.length - 2].y,
                upperHull[upperHull.length - 1].x,
                upperHull[upperHull.length - 1].y,
                'blue' // Set line color for upper hull
            );
        }
    }
  
    // Find the lower hull and visualize
    for (let i = points.length - 1; i >= 0; i--) {
        await sleep(1000);
        while (lowerHull.length >= 2 && isClockwiseTurn(
            lowerHull[lowerHull.length - 2],
            lowerHull[lowerHull.length - 1],
            points[i]
        )) {
            lowerHull.pop();
        }
        lowerHull.push(points[i]);
        // Call drawPointSVG to visualize the points
        drawPointSVG(svgCanvas, points[i].x, points[i].y);

        // Visualize lower hull lines
        if (lowerHull.length >= 2) {
            drawLineSVG(
                svgCanvas,
                lowerHull[lowerHull.length - 2].x,
                lowerHull[lowerHull.length - 2].y,
                lowerHull[lowerHull.length - 1].x,
                lowerHull[lowerHull.length - 1].y,
                'green' // Set line color for lower hull
            );
        }
    }
  
    // Remove duplicate points (start and end points)
    upperHull.pop();
    lowerHull.pop();
    
    // Combine upper and lower hulls and return
    return upperHull.concat(lowerHull);
}


// Function to visualize the convex hull step by step
async function drawConvexHullStepByStep(points) {
    const canvas = document.getElementById('canvas');
    canvas.innerHTML = ''; // Clear previous visualization

    // Get the canvas div
    const canvasDiv = document.getElementById('canvas');
    const canvasRect = canvasDiv.getBoundingClientRect();

    // Create an SVG container with the dimensions of the canvas div
    const svgCanvas = document.createElementNS("http://www.w3.org/2000/svg", "svg");
    svgCanvas.setAttribute("width", canvasRect.width); // Set SVG width as canvas div's width
    svgCanvas.setAttribute("height", canvasRect.height); // Set SVG height as canvas div's height
    canvasDiv.appendChild(svgCanvas); // Append SVG to canvas div

    // Compute and draw the final convex hull
    const convexHull = await DivideNconquer(points, svgCanvas);
    console.log(convexHull);
    // Draw the final convex hull using drawLineSVG
    for (let i = 0; i < convexHull.length; i++) {
        await sleep(1000);
        const nextIndex = (i + 1) % convexHull.length;
        drawLineSVG(
            svgCanvas,
            convexHull[i].x,
            convexHull[i].y,
            convexHull[nextIndex].x,
            convexHull[nextIndex].y,
            '#FF0000' // Set hull color
        );
    }
}

// Function to generate random points and visualize the convex hull
function generateAndDrawConvexHull(numPoints) {
    const points = generateRandomPoints(numPoints);
    console.log(points);
    drawConvexHullStepByStep(points);
}