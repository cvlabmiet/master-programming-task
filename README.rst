About
=====

This project is intended to test students skills in C++ language.

Tasks list
----------

#. I/O stream manipulators.

#. Iterator.

#. Proxy object.

#. Using of ``std::variant``.

#. Parsers by ``boost::spirit::x3``:

   * csv;
   * json.

#. Type map to describe mapping of compile-time types to runtime values.

How to build?
=============

Just use `cmake <https://cmake.org>`_::

    $ mkdir build
    $ cd build
    build/ $ cmake ..
    build/ $ make -j
    build/ $ ctest

If you want to work with particular project::

    build/ $ cmake ../iterator
    build/ $ make -j
    build/ $ ctest

Another approach is to use docker image ``igsha/cxx-miet``.

#. Install `docker <https://www.docker.com>`_.

#. Pull image and start docker-session::

        $ docker run -u `id -u`:`id -g` -v $PWD:/data -it igsha/cxx-miet:0.1
        bash-4.4$ <-- this means you are in docker-session

   * once downloaded session will be available locally;
   * flag ``-u `id -u`:`id -g``` is used to bring the same permissions into docker as your local user permissions;
   * flag ``-v $PWD:/data`` is used to mount your current source directory into docker like folder ``/data``;
   * notes for Windows users: you don't need flag ``-u``, replace ``$PWD`` with the name of current directory.

#. Inside docker-session call the same command sequence like was done above (``mkdir``, ``cd``, ``cmake``, etc.).

#. To exit docker-session press ``Ctrl-D`` or type ``exit`` command.

How to work with projects
=========================

Each project is a complete cmake-project with

* ``CMakeLists.txt``;
* ``include`` that represent "source" of a project;
* ``tests`` - is a main part to check task.

Students should work only with files inside ``include`` folder.
The main criteria is to pass all tests of a project.

How to answer in-source questions
=================================

There are some questions in the source of projects that have the form of C-comments ``//?``.
Print the answer just below a question using the form of C-comment ``//!``.

Use these questions as a hint to a task.

Additional questions
====================

#. How to declare and define function within another function?

#. How to copy lambda?

#. How to call non-constant method of a member within constant method?

   .. code::

        struct cba
        {
            std::ostream& o;
        }

        struct abc
        {
            void mark() const
            {
                obj.o << 123;
            }

            ?cba? obj;
        }

[optional] Write complete project (``CMakeLists.txt``, folder hierarchy and tests).
Themes:

* `INI-parser <https://en.wikipedia.org/wiki/INI_file>`_ with EBNF in comments;
* implement iterator on multidimensional array with the ability to choose the direction of iterations (by x-, y- or z-axis, etc.);
* provide example to work with `google-protobuf <https://developers.google.com/protocol-buffers>`_.
