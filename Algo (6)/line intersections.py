import tkinter as tk

class LineIntersectGUI:
    def __init__(self, master):
        self.master = master
        self.master.title("Line Intersection Checker")

        self.canvas = tk.Canvas(self.master, width=400, height=400)
        self.canvas.pack()

        self.label = tk.Label(self.master, text="Click two points to create Line 1")
        self.label.pack()

        self.points_line1 = []
        self.points_line2 = []

        self.canvas.bind("<Button-1>", self.on_click)

        self.method_var = tk.StringVar()
        self.method_var.set("ccw")  # Default method
        methods = ["ccw", "algebraic", "bounding_box"]
        self.method_dropdown = tk.OptionMenu(self.master, self.method_var, *methods, command=self.on_method_change)
        self.method_dropdown.pack()

    def on_click(self, event):
        if len(self.points_line1) < 2:
            self.points_line1.append((event.x, event.y))
            if len(self.points_line1) == 2:
                self.draw_line(self.points_line1)
                self.label.config(text="Click two points to create Line 2")
        else:
            self.points_line2.append((event.x, event.y))
            if len(self.points_line2) == 2:
                self.draw_line(self.points_line2)
                self.check_intersection()

    def draw_line(self, points):
        self.canvas.create_line(points, fill="black")

    def check_intersection(self):
        method = self.method_var.get()
        if method == "ccw":
            intersect, ccw1, ccw2, ccw3, ccw4 = self.do_lines_intersect_ccw(self.points_line1, self.points_line2)
            result_text = f"Lines are {'intersecting' if intersect else 'not intersecting'}.\n"
            result_text += f"CCW1: {ccw1}, CCW2: {ccw2}, CCW3: {ccw3}, CCW4: {ccw4}"
            self.label.config(text=result_text)
        elif method == "algebraic":
            intersect = self.do_lines_intersect_algebraic(self.points_line1, self.points_line2)
            if intersect:
                self.label.config(text="Lines are intersecting!")
            else:
                self.label.config(text="Lines are not intersecting.")
        elif method == "bounding_box":
            intersect = self.do_lines_intersect_bounding_box(self.points_line1, self.points_line2)
            result_text = f"Lines are {'intersecting' if intersect else 'not intersecting'}.\n"
            self.label.config(text=result_text)

    def on_method_change(self, *args):
        # Clear canvas and reset points when method is changed
        self.canvas.delete("all")
        self.label.config(text="Click two points to create Line 1")
        self.points_line1 = []
        self.points_line2 = []

    def ccw(self, A, B, C):
        return (C[1] - A[1]) * (B[0] - A[0]) - (B[1] - A[1]) * (C[0] - A[0])

    def do_lines_intersect_ccw(self, line1, line2):
        A, B = line1
        C, D = line2
        ccw1 = self.ccw(A, B, C)
        ccw2 = self.ccw(A, B, D)
        ccw3 = self.ccw(C, D, A)
        ccw4 = self.ccw(C, D, B)

        intersect = ccw1 * ccw2 < 0 and ccw3 * ccw4 < 0

        return intersect, ccw1, ccw2, ccw3, ccw4

    def calculate_line_equation(self, point1, point2):
        x1, y1 = point1
        x2, y2 = point2

        if x2 - x1 == 0:
            return None, x1  # Vertical line, return None as slope and x-coordinate as constant
        else:
            slope = (y2 - y1) / (x2 - x1)
            intercept = y1 - slope * x1
            return slope, intercept

    def do_lines_intersect_algebraic(self, line1, line2):
        slope1, intercept1 = self.calculate_line_equation(*line1)
        slope2, intercept2 = self.calculate_line_equation(*line2)

        if slope1 is None and slope2 is None:
            return line1[0][0] == line2[0][0]  # Vertical lines are intersecting if x-coordinates are the same
        elif slope1 is None:
            x = line1[0][0]
            y = slope2 * x + intercept2
        elif slope2 is None:
            x = line2[0][0]
            y = slope1 * x + intercept1
        else:
            # Solve for intersection point
            x = (intercept2 - intercept1) / (slope1 - slope2)
            y = slope1 * x + intercept1

        # Check if the intersection point lies within the line segments
        x_values = [point[0] for point in line1 + line2]
        y_values = [point[1] for point in line1 + line2]
        return min(x_values) <= x <= max(x_values) and min(y_values) <= y <= max(y_values)

    def do_lines_intersect_bounding_box(self, line1, line2):
        A, B = line1
        C, D = line2

        # Calculate bounding boxes
        bbox_line1 = [min(A[0], B[0]), min(A[1], B[1]), max(A[0], B[0]), max(A[1], B[1])]
        bbox_line2 = [min(C[0], D[0]), min(C[1], D[1]), max(C[0], D[0]), max(C[1], D[1])]

        # Check for intersection based on bounding boxes
        intersect = not (bbox_line1[2] < bbox_line2[0] or  # Line1 is to the left of Line2
                         bbox_line1[0] > bbox_line2[2] or  # Line1 is to the right of Line2
                         bbox_line1[3] < bbox_line2[1] or  # Line1 is above Line2
                         bbox_line1[1] > bbox_line2[3])     # Line1 is below Line2

        return intersect

if __name__ == "__main__":
    root = tk.Tk()
    app = LineIntersectGUI(root)
    root.mainloop()
