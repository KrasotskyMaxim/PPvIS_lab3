# Ocean model
When doing this option, I had to develop a game model of the oceanic world. Actually, the world in which the inhabitants of the ocean live, is a rectangular field of arbitrary size. The rectangular field is divided into equal squares (cells), and each cell can have a maximum of four inhabitants. Modeling of life in such a world takes place in a step-by-step mode, in which each step contains the following clearly defined stages:

- Moving
- Eating
- Reproduction
- Death from old age or starving
  
---
The behavior of the inhabitants in each of the stages will depend on the type of inhabitant. There are two main types of inhabitants with the following properties:

- Plankton:
  * only one plant can be in the cell
  * don`t move
  * has hitpoints
    - waste some hp evepy step *(dying effect)*
    - plankton can multiply to a neighboring cell even if there is already another plankton with an incomplete percentage of life *(in this case, reproduction will update life to 100)*

- Predator:
  - moves *(the number of cells that can be moved depends on the type
inhabitant)*;
  - has a size *(depending on the type of inhabitant)*:
    - a larger predator needs to eat more;
    - a larger predator can eat a larger inhabitant of the ocean;
  - has a lifetime;
  - can die if a certain number of moves are hungry;
  - feeds on plankton or another predator *(depending on the gastronomic preferences of the inhabitant of the ocean)*:
    - the victim must be on the same cell;
    - always eats the whole inhabitant, if he did not run away;
  - reproduction:
    - need a pair of individuals to reproduce on the same cell;
    - the cub is born immediately on the same cell.

---
Having studied these rules, I needed to develop an object model of the subject area and a program that would carry out modeling of the process of life. And the inhabitants of the world will be specific types of inhabitants. For example, a shark is a khishch-
A medium-sized nick that can move 2 cells per turn feeds on planktonomb but not whales. As can be seen from the example, a particular species of inhabitant may have some specialty.
Qualities and some special behavior. This does not apply to plankton, because there should be only one type of plankton in the model. When developing the class hierarchy, an attribute of any object-oriented language, such as inheritance, was applied.

---
The developed object model meet the following requirements:
- other classes of species of inhabitants of the ocean *(quantity at the discretion of the developer)*
- occupant classes should be hierarchical so that the general properties and logic of work
described by a superclass
- Introduction of the description of the ocean world *(playing field)*
- provides a mechanism for modeling the ocean world
- classes that provide unloading of the model from a text file

---
A program implemented on the basis of the developed model should:
- receive the name of the input file with a description of the world and a description of the operating mode *(automatical simulation or step-by-step simulation pending confirmation from user)* via a command argument;
- output to the console the state of the playing field on each move. 

# Using

To start creating ocean model you sould to puy in console model file name with settings, for example ***oecans/model1.txt***

# Setting File Struct
10 - *count of ocean living cycles*

3 - *plankton count*

Plankton **coordinates**:

- 0 1 0
- 0 2 0
- 2 1 3


2 - *shark count*

Shark **coordinates** and last number is shark **sex** (0 - *female*  1 - *male*):

- 1 0 1 1
- 2 3 0 0

3 - *whale count*

Whale **coordinates** and last number is Whale **sex** (0 - *female*  1 - *male*):

- 2 2 2 0
- 1 2 3 1
- 4 4 3 1

**END**.