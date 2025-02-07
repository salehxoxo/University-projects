import pygame
import random
import time
import heapq

# Colors
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
DARK_YELLOW = (204, 204, 0)
RED = (255, 0, 0)
GREY = (169, 169, 169)  # Grey color for walls

# Initialize Pygame
pygame.init()

# Set up the screen
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Self Driving Car Simulation")

# Grid settings
GRID_SIZE = 20
CELL_SIZE = SCREEN_WIDTH // GRID_SIZE

# Randomly generate map with coins, potholes, start, goal states, and walls
def generate_map(grid_size, num_coins, num_potholes, num_goals, num_walls):
    map_data = [[' ' for _ in range(grid_size)] for _ in range(grid_size)]
    coins = []
    potholes = []
    start_positions = []
    goal_positions = []
    walls = []
    for _ in range(num_coins):
        x, y = random.randint(0, grid_size - 1), random.randint(0, grid_size - 1)
        coins.append((x, y))
        map_data[y][x] = 'C(' + str(random.randint(1, 10)) + ')'
    for _ in range(num_potholes):
        x, y = random.randint(0, grid_size - 1), random.randint(0, grid_size - 1)
        potholes.append((x, y))
        map_data[y][x] = 'P(' + str(random.randint(-10, -1)) + ')'
    for _ in range(num_goals):
        x, y = random.randint(0, grid_size - 1), random.randint(0, grid_size - 1)
        goal_positions.append((x, y))
        map_data[y][x] = 'G'
    for _ in range(1):
        x, y = random.randint(0, grid_size - 1), random.randint(0, grid_size - 1)
        start_positions.append((x, y))
        map_data[y][x] = 'S'
    return map_data, coins, potholes, start_positions, goal_positions, walls

# Draw the map
def draw_map(map_data, coins, potholes, start_positions, goal_positions, walls):
    screen.fill(WHITE)
    for y in range(len(map_data)):
        for x in range(len(map_data[y])):
            rect = pygame.Rect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE)
            pygame.draw.rect(screen, GREEN, rect, 1)
            if map_data[y][x] != ' ':
                font = pygame.font.Font(None, 20)
                if map_data[y][x] == 'G':
                    color = RED
                elif map_data[y][x] == 'S':
                    color = GREEN
                elif map_data[y][x].startswith('C'):
                    color = DARK_YELLOW
                elif map_data[y][x] == 'W':
                    color = GREY
                else:
                    color = BLUE
                text = font.render(map_data[y][x], True, color)
                screen.blit(text, (x * CELL_SIZE + 5, y * CELL_SIZE + 5))
    for coin in coins:
        pygame.draw.circle(screen, DARK_YELLOW, (coin[0] * CELL_SIZE + CELL_SIZE // 2, coin[1] * CELL_SIZE + CELL_SIZE // 2), 5)
    for pothole in potholes:
        pygame.draw.circle(screen, BLUE, (pothole[0] * CELL_SIZE + CELL_SIZE // 2, pothole[1] * CELL_SIZE + CELL_SIZE // 2), 5)
    for wall in walls:
        pygame.draw.rect(screen, GREY, (wall[0] * CELL_SIZE, wall[1] * CELL_SIZE, CELL_SIZE, CELL_SIZE))

# DFS Algorithm
def dfs(grid, start, goal_positions):
    stack = [(start, [start])]
    visited = set()
    while stack:
        (x, y), path = stack.pop()
        if (x, y) in goal_positions:
            return path
        if (x, y) in visited:
            continue
        visited.add((x, y))
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < len(grid[0]) and 0 <= ny < len(grid) and grid[ny][nx] != 'W' and (nx, ny) not in visited:
                stack.append(((nx, ny), path + [(nx, ny)]))
    return None

# BFS Algorithm
def bfs(grid, start, goal_positions):
    queue = [(start, [start])]
    visited = set()
    while queue:
        (x, y), path = queue.pop(0)
        if (x, y) in goal_positions:
            return path
        if (x, y) in visited:
            continue
        visited.add((x, y))
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < len(grid[0]) and 0 <= ny < len(grid) and grid[ny][nx] != 'W' and (nx, ny) not in visited:
                queue.append(((nx, ny), path + [(nx, ny)]))
    return None

# A* Algorithm
def heuristic(a, b):
    return abs(b[0] - a[0]) + abs(b[1] - a[1])

def astar(grid, start, goal_positions):
    heap = [(0, start, [])]
    visited = set()
    while heap:
        cost, current, path = heapq.heappop(heap)
        if current in goal_positions:
            return path
        if current in visited:
            continue
        visited.add(current)
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx, ny = current[0] + dx, current[1] + dy
            new_cost = cost + 1
            if 0 <= nx < len(grid[0]) and 0 <= ny < len(grid) and grid[ny][nx] != 'W' and (nx, ny) not in visited:
                heapq.heappush(heap, (new_cost + heuristic((nx, ny), goal_positions[0]), (nx, ny), path + [(nx, ny)]))
    return None

# Main loop
def main():
    # Take user input
    grid_size = int(input("Enter grid size: "))
    num_goals = int(input("Enter number of goal states: "))
    num_cars = int(input("Enter number of cars: "))

    # Generate map
    num_potholes = random.randint(1, grid_size//2)  # Random number of potholes
    num_coins = random.randint(1, grid_size) 
    num_walls = random.randint(1, grid_size**2 // 4)  # Random number of walls
    map_data, coins, potholes, start_positions, goal_positions, walls = generate_map(grid_size, num_coins, num_potholes, num_goals, num_walls)

    # Draw initial map
    draw_map(map_data, coins, potholes, start_positions, goal_positions, walls)
    pygame.display.flip()

    # Store results for each car
    car_results = []

    # Generate a single start position for all cars
    start = start_positions[0]

    # Variable to check if the user finished adding walls
    walls_added = False

    # Algorithm choices for each car
    car_algorithms = []
    for i in range(num_cars):
        algorithm = input(f"Enter algorithm choice for Car {i+1} (DFS, BFS, or A*): ").lower()
        while algorithm not in ['dfs', 'bfs', 'a*']:
            print("Invalid choice. Please enter 'dfs', 'bfs', or 'a*'.")
            algorithm = input(f"Enter algorithm choice for Car {i+1} (DFS, BFS, or A*): ").lower()
        car_algorithms.append(algorithm)

    # Main event loop
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                x, y = event.pos
                cell_x = x // CELL_SIZE
                cell_y = y // CELL_SIZE
                if event.button == 1:  # Left mouse button
                    if (cell_x, cell_y) not in coins and (cell_x, cell_y) not in potholes and (cell_x, cell_y) not in start_positions and (cell_x, cell_y) not in goal_positions:
                        walls.append((cell_x, cell_y))
                        map_data[cell_y][cell_x] = 'W'
                        draw_map(map_data, coins, potholes, start_positions, goal_positions, walls)
                        pygame.display.flip()  # Update the display after adding walls
                elif event.button == 3:  # Right mouse button
                    if (cell_x, cell_y) in walls:
                        walls.remove((cell_x, cell_y))
                        map_data[cell_y][cell_x] = ' '
                        draw_map(map_data, coins, potholes, start_positions, goal_positions, walls)
                        pygame.display.flip()  # Update the display after removing walls
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    walls_added = True  # Set the flag to True when spacebar is pressed

        # Once walls are added, proceed with car movement and algorithm execution
        if walls_added:
            # Car movement
            for i in range(num_cars):
                algorithm = car_algorithms[i]
                goal = random.choice(goal_positions)
                if algorithm == 'dfs':
                    path = dfs(map_data, start, goal_positions)
                elif algorithm == 'bfs':
                    path = bfs(map_data, start, goal_positions)
                elif algorithm == 'a*':
                    path = astar(map_data, start, goal_positions)

                if path:
                    # Visualize car movement
                    car_color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))  # Random color for each car
                    points = 0
                    for step in path:
                        draw_map(map_data, coins, potholes, start_positions, goal_positions, walls)
                        pygame.draw.circle(screen, car_color, (step[0] * CELL_SIZE + CELL_SIZE // 2, step[1] * CELL_SIZE + CELL_SIZE // 2), 10)
                        pygame.display.flip()
                        time.sleep(0.3)  # Adjust speed of car movement

                        # Check if the step coordinates are within the valid range of the map_data list
                        if 0 <= step[0] < len(map_data[0]) and 0 <= step[1] < len(map_data):
                            # Calculate points earned by the car if the step is valid
                            if step in coins:
                                points += int(map_data[step[1]][step[0]].split('(')[1][:-1])
                            elif step in potholes:
                                points += int(map_data[step[1]][step[0]].split('(')[1][:-1])

                    car_results.append({'Car': i+1, 'Algorithm': algorithm.upper(), 'Points': points, 'Time': len(path)})
                running = False  # Exiting the loop after the first iteration

    # Display results for each car
    for result in car_results:
        print(f"Car {result['Car']}: Algorithm: {result['Algorithm']}, Points: {result['Points']}, Time taken: {result['Time']} steps.")

    pygame.quit()

if __name__ == "__main__":
    main()
