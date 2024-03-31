# CompBasedFlexAssembly
a GitHub repository showcasing a component-based framework for simulating a flexible assembly automation system, as detailed in our research on enhancing manufacturing adaptability and efficiency.
The repository demonstrates the practical implementation of a laboratory prototype assembly line, showcasing our novel framework for flexible manufacturing systems.

## Overview

The codebase herein is designed to illustrate the application of a state-diagram-based modeling approach to a flexible assembly automation system. The presented prototype serves as a proof-of-concept for the effectiveness of our proposed framework in managing assembly processes.

## Implementation Details

The implementation encompasses the setup of a laboratory prototype assembly line, integrating a variety of industrial devices, sensors, and actuators. The main controller, Zynq-7020 SoC, orchestrates the assembly tasks, harnessing the power of its dual-core ARM Cortex-A9 processor and customizable FPGA section. A multi-axis robotic arm, along with a three-axis motion platform, performs precise assembly and labeling tasks, underpinned by our framework's auto-conversion feature that generates lower-level C code fit for the industrial environment.

## Laboratory Prototype Assembly Line

The repository includes detailed design and configuration files for the assembly line, which is composed of an adjustable-speed conveyor belt, a robotic arm, motion platforms, and a thermal printing head. These components work in tandem to fulfill custom product orders, simulating a real production process.

## Hardware Selection and Configuration

The repository details the selection and configuration of various hardware devices, including their operational parameters and roles in the assembly process. Each component is carefully chosen to represent typical industrial applications, and to demonstrate the feasibility and scalability of our approach.

## Usage

To explore the prototype's capabilities, users are invited to review the source code, replicate the hardware setup, and observe the interplay between the software and physical components. 

## License

This project is released under a suitable open-source license, allowing for both academic and industrial use, ensuring the reproducibility of research and fostering innovation in the field of flexible assembly automation systems.
