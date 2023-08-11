
> Instructor: [Dr. H. Farbeh](https://scholar.google.com/citations?user=PAZOYiAAAAAJ&hl=en)

> Summer 2022


This readme provides an overview of the Washing Machine Task Scheduling project, outlining task characteristics, scheduling algorithms, and simulation methodologies.

## Task Characteristics

> In this project, tasks are categorized into critical and preemptive groups. Tasks two, three, and five possess critical regions, rendering them non-preemptive under the NPP scheduling algorithm. Once initiated, these tasks cannot be interrupted until completion. Conversely, tasks one and four are preemptive, capable of interruption by higher-priority tasks.

> Tasks exhibit varying deadlines. Task one holds the most stringent deadline, necessitating rapid completion. Tasks two and three have intermediate deadlines and secondary priority. Task four has a relatively lenient deadline and lower priority, while task five boasts the lowest deadline and priority.

## Scheduling Algorithms

> The project employs the Non-Preemptive Priority (NPP) and Earliest Deadline First (EDF) scheduling algorithms. NPP facilitates sequential execution without interruption, while EDF prioritizes tasks with the closest deadlines, promoting optimal resource usage.

## Simulation Approach

> For performance evaluation, the Proteus simulation environment is utilized. The simulation provides a visual representation of task execution, aided by LEDs corresponding to various washing machine functions. The project's execution order, task priorities, and preemptive nature are observable through LED activation patterns during simulation.

## Project Goals

> The primary objective is to showcase embedded systems' practical application and simultaneous operation execution. By implementing NPP and EDF algorithms, the project demonstrates effective task scheduling and resource management on a washing machine.

## Usage

> To simulate the project, load the provided configuration into the Proteus environment. Observe the LED activations, depicting the execution status of different washing machine functions. Analyze how task priorities, deadlines, and preemptive behavior affect overall project performance.

## Conclusion

> The Washing Machine Task Scheduling project exemplifies efficient task management in an embedded system context. Through NPP and EDF algorithms and the Proteus simulation environment, the project offers insights into scheduling strategies, showcasing the optimal execution of washing machine operations.
<img width="1184" alt="wash" src="https://github.com/HeliaHashemipour/WashingMachine-RealTime/assets/71961438/84d777c1-a635-41a1-81ed-a7cefa991d90">


> 
