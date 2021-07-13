1. High level goals:
 This supervision is aimed at you looking and learning about a language that you
 haven't used extensively so far (C++), while both using existing Python
 knowledge and understanding differences (learning new things) to gain a better
 prspective on programming tasks in general. This is important because some of
 the elements you are becoming re-accustomed to are not tied to a particular
 language but to a way of thinking. So it is useful to be able to generalize
 from your particular Python experience and see trade-offs made in other
 programming languages. Furthermore, some concepts might be harder to come
 across when using Python, as the language abstracts away some lower-level
 details.

2. Particular skills being exercised:
 - reading and understanding a small code base
 - exercising more independence in coding and documentation exploration
 - understanding encapsulating data and code operating on that data (classes)
 - understanding memory and object ownership issues
 - passing values and references to functions as arguments
 - how to pick container types (list, vector, map) suitable to your needs
 - identifying and fixing potential bugs in code
 - [optional] using git (source code management)

3. Task outline:
 You will be exposed to relatively simple modern C++ code written by somebody
 else, and you will need to answer some questions about it and complete the
 tasks outlined in the next section (I suggest you approach them in order).
 While doing so you will:
 - understand how the code is structured and what it achieves
 - think about what the code does and explore how it works by executing it
   / printing to stdout
 - identify potential problems with the code and fix them
 - think about different ways in which the code might have been written
   
4. Required independent reading topics (C++):
  - namespaces
  - types & classes and objects
  - objects allocated on the heap vs stack
  - vectors (std::vector) & their behaviour
  - smart pointers (std::unique_ptr, std::shared_ptr, std::weak_ptr) and their uses
  - maps (std::map) & their uses
  - standard I/O

  Some possible resources:
    - https://www.cl.cam.ac.uk/teaching/2021/ProgC/materials.html
    - https://www.learncpp.com/
    - https://www.geeksforgeeks.org/basic-input-output-c/
    - https://en.cppreference.com/w/
    - https://blog.kotlin-academy.com/programmer-dictionary-class-vs-type-vs-object-e6d1f74d1e2e
    - https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/

5. Tasks      
5.1. Download code and make sure you have a working c++ compiling environment:
     A. Download
     - you download the code from https://github.com/lc525/cpp-supervision-1
     - instead of downloading, if you have git installed you can also simply
       run: $> git clone https://github.com/lc525/cpp-supervision-1
     - all directory references from now on are relative to the directory where
       you've downloaded the code or cloned it using git (cloning will create
       a cpp-supervision-1 directory in the directory where the command is
       executed)

     B. Building and Exploring the build environment
     - this will require you have `gcc` and `make` installed
     - build the code by executing make with the target "hello" in the directory
       where code was downloaded; this will build the project in accordance to
       instructions in the `Makefile` file: 
          $> make hello
     - inspect the build output and make sure there are no errors in the build
       process
     - if there are errors, report them back to your supervisor via email or
       xmpp
     - if all went well, you should have an executable binary in the `build`
       subdirectory:
          $> ./build/hello
     - there are other available make targets in the Makefile:
          - all : builds all binaries in the project
          - clean: removes build objects and binaries, together with build
            directory
          - hello: builds a simple "Hello world" C++ application to test
            compiler toolchain
          - query: compiles the code constituting the "meat" of this supervision

5.2. Read code, understand project structure:
    - Start by reading the class definitions in include/uni/tripos.h
    - Refer to C++ documentation (like en.cppreference.com) for understanding
      datatypes which are new to you and what functionality they offer
    - The classes are just defined, you will have to write most function
      implementations as part of this supervision. You will write the
      implementations in src/tripos.cpp
    - Some of the function definitions in tripos.h will need improving/fixing as
      you understand more about what data types are appropiate and which class
      should own what memory.
    - As a starting point for some of that exploration, there is an application
      already using the "tripos" classes, in src/query.cpp

5.3 Start implementing class functionality, fix errors / improve code as you go:
    - The src/query.cpp file has comments guiding you on what to do, and each
      task will require you to implement more of the functions from classes
      in include/uni/tripos.h
    - Where you observe the need to modify pre-existing code, add a comment
      mentioning the reason for modifying it (what bug could it introduce, what
      compilation problem you needed to fix, how your change improves things,
      etc).

5.4 Extension
    - Add a code to query.cpp which lists for each student how many supervisions
    do they have outstanding and for what courses.
