from tkinter import messagebox, Tk
import pygame
import os
import sys
import math
#Beginning instructionss
#below are the basic controls
msg1 = "Read the follow instructions carefully to understand how to navigate around the visualization.\n"
msg2 = "\n\n'Left-mouse click': Adds a wall. Algorithm can't look into the box or pass through it. Holding left-button and dragging it will allow you to select multiple boxes. Algorithm can pass through tiny holes through the said walls if they aren't enclosed properly diagonally"
msg3 = "\n\n'Right-mouse click': Selects the Target Box. Can only be one at a time. "
msg4 = "\n\n'Enter': Pressing the 'Enter' key runs the Visualization."
msg5 = "\n\nImportant: Don't mark Target node in the wall nor mark wall in the target node. Algorithm can't look inside the wall."
msg6 = "\nSelection of a single target box/node is necessary for the visualization."
msg7 = "\n\n\nDo you want a basic summmary on what do the coloured nodes/boxes in the visualization represents?"
msg = msg1 + msg2 + msg3 + msg4 + msg5 + msg6 + msg7
k = messagebox.askyesno("","Welcome to the Visualization of the Pathfinding Algorithm by Huzaifa, Saleh and Ahmed \n\nDo you want instructions on how to navigate this code?")
if k == 1:
    k2 = messagebox.askyesno("", msg)
    if k2 == 1: #explaining the algorithm
        ms1 = "Assume box and node to mean the same thing.\n\n"
        ms2 = "Light blue box = starting box\n"
        ms3 = "Yellow box = target box\n"
        ms4 = "\nWhen the Algorithm runs:"
        ms5 = "\nGreen boxes are the visited boxes"
        ms6 = "\nRed Boxes represents the boxes that are 'queued' to be visited later by the algorithm"
        ms7 = "\nDark blue boxes together represents the shortest path between starting and target box"
        ms = ms1 + ms2 + ms3 + ms4 + ms5 + ms6 + ms7
        messagebox.showinfo("", ms)
c1 = "We can visualize two path-finding algorithms. Dijkstra's Algorithm and A* Algorithm"
c2 = "\n\nSelect 'Yes' to visualize Dijsktra's Algorithm"
c3 = "\nSelect 'No' to visualize A* Algorithm"
c = c1 + c2 + c3
chosen = messagebox.askyesno("", c)
        

#ACTUAL CODE!!!



#This decides how big our window that pops is going to be by pixels. You can change it if you want. 
window_width = 700
window_height = 700
#displays the window. argument = (width, height)
window = pygame.display.set_mode((window_width, window_height))
#Making the grid:
#How many columns and rows? You can change it if you want.
columns = 40
rows = 40

# Deciding the dimensions of a single box
box_width = window_width // columns
box_height = window_height // rows

#Initializing the arrays. In this Grid, all the information regarding each box which will show up on the window will be stored.
grid = []
queue = [] #going to store our boxes in the queue
path = []
closeSet = []
openSet = []

class Box:
    #i and j are the coordinates for a box
    def __init__(self, i, j):
        #tells the position of the box
        self.x = i
        self.y = j
        #flagging starting, walls, and target boxes. For those specific instances of the box, the flag will be set to true i assume
        self.start = False
        self.wall = False
        self.target = False
        #For Tranversal (3rd part)
        self.queued = False
        self.visited = False
        self.neighbours = [] #neighbours of each individual 
        #for path
        self.prior = None
        
        #for A* algo
        self.f, self.g, self.h = 0, 0, 0
        #self.prev = None
        
    #help us draw individual boxes on canvas
    def draw(self, win, color):
        #argument = (window, colour, (x-coordinate, y-coordinate, width, height))
        pygame.draw.rect(win, color, (self.x * box_width, self.y * box_height, box_width-2, box_height-2))

    #function that sets the individual neighbours for every box
    def set_neighbours(self):
        #taking care of the horizontal neighbours for every box
        if self.x > 0:
             #appending to the neighbours array the individual neighbours of the box
            self.neighbours.append(grid[self.x - 1][self.y])
        if self.x < columns - 1:
            self.neighbours.append(grid[self.x + 1][self.y])
        #taking care of the verticial neighbours for every box
        if self.y > 0:
            self.neighbours.append(grid[self.x][self.y - 1])
        if self.y < rows - 1:
            self.neighbours.append(grid[self.x][self.y + 1])
        #Add Diagonals
        if self.x < columns - 1 and self.y < rows - 1:
            self.neighbours.append(grid[self.x+1][self.y+1])
        if self.x < columns - 1 and self.y > 0:
            self.neighbours.append(grid[self.x+1][self.y-1])
        if self.x > 0 and self.y < rows - 1:
            self.neighbours.append(grid[self.x-1][self.y+1])
        if self.x > 0 and self.y > 0:
            self.neighbours.append(grid[self.x-1][self.y-1])


#Creation of proper grid
#filling the grid with all the instances of the class box
for i in range(columns):
    arr = []
    for j in range(rows):
        arr.append(Box(i, j)) #creating a box object and appending it to the array(creating a column)
    grid.append(arr) #appending the column(array) to the grid

#Set neighbours for each box by :
#iterating over all the i and j indexes (that's how we know boxes position)
#we are going to set neighbours by calling the neighbours function on the individual box
for i in range(columns):
    for j in range(rows):
        grid[i][j].set_neighbours()

#setting up the starting box
start_box = grid[0][0]
start_box.start = True
start_box.visited = True
queue.append(start_box) #first item in our queue and starting point of our algo

#this function will help us calculate the distance between two boxes (heuristics) for A* algo
def heuristics(a, b):
    return math.sqrt((a.x - b.x)**2 + abs(a.y - b.y)**2)

#he openSet list is used in the A* pathfinding algorithm to keep track of the boxes that have been discovered but not yet evaluated. 
#The start_box is added to openSet.
openSet.append(start_box)
def main():
    begin_search = False #when true, algorithm starts working. This variable will help us start the algo when we press enter
    target_box_set = False  #end 
    searching = True #this variable will help stop the algo after the end point has been found
    target_box = None #store the box we are going to reach
    flag = False

    while True:
        for event in pygame.event.get():
             #this code block alls to close the window when we press "x" on the window on top-right
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            #MOUSE CONTROLS
            elif event.type == pygame.MOUSEMOTION:
                x = pygame.mouse.get_pos()[0]
                y = pygame.mouse.get_pos()[1]
                # Draw Wall
                if event.buttons[0]:  #when the left buttom mouse is clicked
                    i = x // box_width
                    j = y // box_height
                    grid[i][j].wall = True
                # Set Target
                if event.buttons[2] and not target_box_set:  #when the right buttom mouse is clicked
                    i = x // box_width
                    j = y // box_height
                    target_box = grid[i][j]
                    target_box.target = True
                    target_box_set = True

            #We are looking for a key press on the keyboard, should be an "Enter key"
            if event.type == pygame.KEYDOWN and target_box_set:
                begin_search = True

        #Algorithm using Dijkstra and BFS!
        if begin_search and chosen == 1:
            if len(queue) > 0 and searching:
                current_box = queue.pop(0)
                current_box.visited = True
                if current_box == target_box:
                    searching = False
                    #path-finding time! Trace back
                    while current_box.prior != start_box:
                        path.append(current_box.prior)
                        current_box = current_box.prior
                    #print("Done")
                else:
                    for neighbour in current_box.neighbours:
                        if not neighbour.queued and not neighbour.wall:
                            neighbour.queued = True
                            neighbour.prior = current_box
                            queue.append(neighbour)
            elif searching:  # If the queue is empty and we're still searching, then there's no solution
                Tk().wm_withdraw()
                messagebox.showinfo("", "There seems to be no ANSWER!")
                searching = False
            else:
                print("Done")
                  
        #A* Algorithm!
        if begin_search and chosen == 0:
            if len(openSet) > 0:
                winner = 0
                for i in range(len(openSet)):
                    if openSet[i].f < openSet[winner].f:
                        winner = i

                current = openSet[winner]
                
                if current == target_box:
                    temp = current
                    while temp.prior:
                        path.append(temp.prior)
                        temp = temp.prior 
                    if not flag:
                        flag = True
                        print("Done")
                    elif flag:
                        continue

                if flag == False:
                    openSet.remove(current)
                    closeSet.append(current)

                    for neighbor in current.neighbours:
                        if neighbor in closeSet or neighbor.wall:
                            continue
                        tempG = current.g + 1

                        newPath = False
                        if neighbor in openSet:
                            if tempG < neighbor.g:
                                neighbor.g = tempG
                                newPath = True
                        else:
                            neighbor.g = tempG
                            newPath = True
                            openSet.append(neighbor)
                        
                        if newPath:
                            neighbor.h = heuristics(neighbor, target_box)
                            neighbor.f = neighbor.g + neighbor.h
                            neighbor.prior = current
            else: #if no solution
                if searching:
                    Tk().wm_withdraw()
                    messagebox.showinfo("","There seems to be no ANSWER!")
                    searching = False

        window.fill((0, 0, 0))

        for i in range(columns):
            for j in range(rows):
                box = grid[i][j]
                box.draw(window, (100, 100, 100))
                if flag and box in path:
                    box.draw(window, (25, 120, 250))
                if box.queued:
                    box.draw(window, (200, 0, 0))
                # if box.queue:
                #     box.draw(window, (200, 0, 0))
                if box.visited:
                    box.draw(window, (0, 200, 0))
                if box in path:
                    box.draw(window, (0, 0, 200))
                elif box in closeSet:
                    box.draw(window, (0, 255, 0))
                elif box in openSet:
                    box.draw(window, (255, 0, 0))
                if box.start:
                    box.draw(window, (0, 200, 200))
                if box.wall:
                    box.draw(window, (10, 10, 10))
                if box.target:
                    box.draw(window, (200, 200, 0))

        pygame.display.flip()
        # b = messagebox.askretrycancel("Undertale is the best game. Play it", "Do you want to re-visualize the algorithm?")
        # if b == 1:
        #     os.execl(sys.executable, sys.executable, *sys.argv)


main()
# b = messagebox.askretrycancel("Undertale is the best game. Play it", "Do you want to re-visualize the algorithm?")
# while b == 1:
#     main()

