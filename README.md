### Design Patterns
#### Spring, 2018
#### Prof Y C Cheng
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

## Week 9

find as a function vs find as a _Visitor_
- breaking cyclic dependency: separating FindVisitor in find_visitor.h from Visitor visitor.h
- dealing with folders and links

[_Open-Closed Principle_, _Single Responsibility Principle_](http://butunclebob.com/ArticleS.UncleBob.PrinciplesOfOod)

__Midterm to take place on 4/30, 1:10 pm - 2:40 pm, closed book and notes__

## Week 8

Design problem: find as
- a function or
- a member function of Node?
- _Visitor_

## Week 7

FolderIterator design:
- reuse -> no
- dependency on Folder -> heavy

=> make FolderIterator part of the class Folder

Application of iterator: find

find "path" -name "name"

for example;

find test_data -name hello.cpp -> test_data/hello.hello_cpp
find test_data -name hello* -> test_data/hello.hello_cpp
                               test_data/hello.hello

## Week 6
I made it compile and run after fixing a couple of places but mainly in the file "iterator.h": __#ifdef__ ITERATOR_H ==> __#ifndef__ ITERATOR_H

Reusing test data with [**fixtures**](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests):

Devising a plan:
- create objects of files, directories, and symbolic links
- obtain their sizes
- Hierarchical file system
- __Accessing nodes in file system__
- Constructing a given directory given a pathname
- Adding operations (ls, wc, suffixing, etc.)

_Iterator_
- template
- inner class

## Week 5
_Composite_
- enabling client to treat components and composites _uniformly_
  - total physical size
  - total logical size

_Proxy_
- adding links

## Week 4
_Composite_
- maintaining the _part-whole_ tree structure
  - deleting node from folder
  - which container to use?
- compromise: non-uniformity + compile time check vs. uniformity + runtime check + reasonable default operations

## Week 3
We know the physical size of a file: File::size(). Next, we will
- add folder
- folder and file as node
- hierarchical structure of objects: tree;
  - adding nodes to a folder
_Composite_

## Week 2
We will solve the problem with the the simple _iterative & incremental_ method
[**How to Solve It**](http://htsicpp.blogspot.tw/2014/08/introducing-how-to-solve-it-cpp.html):
- _Understanding the problem_: by constructing an example
- _Devising a plan_: what we must do to make the example work?
- _Carrying out the plan_: test, code, refactor
- _Looking back_

Devising a plan:
- create objects of files, directories, and symbolic links
- obtain their sizes
- Hierarchical file system
- Accessing nodes in file system
- Constructing a given directory given a pathname
- Adding operations (ls, wc, suffixing, etc.)

### Introduction
We will build a unix-like hierarchical file system. Here are [the basic things a file system does](https://www.tutorialspoint.com/unix/unix-file-system.htm).

We will have plenty of opportunities to encounter **design problems**. After analyzing the design problems, we will make use of appropriate design patterns to solve them. The patterns include _Composite_, _Proxy_, _Observer_, _Visitor_, _Template Method_, and _Mediator_.

I will be using the following simple way to write C++ programs. My programs (and your programs will, too) come with a makefile that builds it by typing _make_ in bash. We will use the g++ stack, which should work on most popular OS platforms (e.g., Ubuntu, MacOS, and bash on Ubuntu on Windows).

When coding in class, I will use the editor [Atom](https://atom.io), which comes with syntax highlighting, code completion to make coding easy. I will also use the plugin [PlatformIO IDE Terminal](https://atom.io/packages/platformio-ide-terminal) so that we can access a terminal to build programs without leaving Atom.

## Problem

The file system is used in many apps ranging from document editors (e.g., Atom), file/directory browser, file sync/storage applications (e.g., Dropbox), etc. In these applications, it is necessary to open/save document(s) from/to a selected location in the file system. Many operations on the file system are needed; for example, adding/deleting a file to/from a directory; moving selected files from one directory to another, searching files with a given name, compressing or encrypting a file or a directory, etc. Also, certain information about the files and directories are often needed, for example, the storage space used by a file or a directory, the organization of a directory, etc.

File systems differ in different operating systems. In this problem, we shall assume that Unix file system is used. To be sure, it is possible to provide all of the above operations by invoking system calls and functions that comes in C-binding on Unix systems. Unfortunately, the API bindings are usually terse and difficult to understand and are not suitable for use in the applications. Thus, the problem is to develop an object-oriented API in C++ that is easier to understand and work with. We also want it to be easy to add unforeseen operations to the file system.
