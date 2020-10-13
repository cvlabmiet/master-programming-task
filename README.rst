About
=====

This project is intended to test students skills in C++ language.

Tasks list
----------

#. I/O stream manipulators.
#. Proxy object.
#. Iterator.
#. Using of ``std::variant``.
#. CSV parser by ``boost::spirit::x3``.
#. JSON parser by ``boost::spirit::x3``.
#. Type map to describe mapping of compile-time types to runtime values.
#. Tests for strided range.

How to build?
=============

cmake
-----

Just use `cmake <https://cmake.org>`_::

    $ cmake -B build -GNinja .
    $ cmake --build build
    $ cmake --build build test

If you want to work with particular project, just uncomment (remove ``#`` sign) string ``add_subdirectory`` with the project name.
You can launch the tests from this project only (shown for ``<myproject>``)::

    build/ $ cmake --build .
    build/ $ ctest -R <myproject> -V

The flag ``-V`` shows detailed report.

Or use catch executable directly::

    build/ $ ./<myproject>/tests_<myproject>

Instead of ``cmake --build build`` you can use chosen build generator directly (``ninja`` for the example above).

docker
------

Another approach is to use docker image ``igsha/cxx-miet``.

#. Install `docker <https://www.docker.com>`_.
#. Pull image and start docker-session::

        $ docker run -u `id -u`:`id -g` -v $PWD:/projects -it igsha/cxx-miet:latest
        bash-4.4$ <-- this means you are in a docker-session

   * once downloaded session will be available locally;
   * flag ``-u `id -u`:`id -g``` is used to bring the same permissions into docker as your local user permissions;
   * flag ``-v $PWD:/projects`` is used to mount your current source directory into the docker like folder ``/projects``;
   * notes for Windows users: you don't need flag ``-u``, replace ``$PWD`` with the name of the current directory.
#. Within docker-session call the same command sequence like was done above (``mkdir``, ``cd``, ``cmake``, etc.).
#. To exit docker-session press ``Ctrl-D`` or type ``exit`` command.

nix-shell
---------

If you don't use `NixOS <https://nixos.org>`_, you can still use ``nix-shell`` on linux-like systems.

Install ``nix`` environment by running the command ``curl -L https://nixos.org/nix/install | sh`` and answer several
questions.
Point to the project root directory and run ``nix-shell``.
Then just follow cmake subsection instructions.

Eclipse Che
-----------

You can use https://che.openshift.io to access IDE based on browser eclipse.
You need ``eclipse-che.yml`` configuration file from this repository to correctly setup a workspace.

How to work with projects
=========================

Each project is a subproject with

* ``CMakeLists.txt``;
* ``include`` that represent the "source" of a project;
* ``tests`` is a main part to check task;
* ``README.rst`` that has some useful information about the project.

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

#. How to initialize members of the same class in different constructors?
#. How to initialize a member in separate function within member initializer list?

[optional] Write complete project (``CMakeLists.txt``, folder hierarchy and tests).
Themes:

* `INI-parser <https://en.wikipedia.org/wiki/INI_file>`_ with EBNF in comments;
* implement iterator of multidimensional array with the ability to choose the direction of iterations (by x-, y- or z-axis, etc.);
* provide example to work with `google-protobuf <https://developers.google.com/protocol-buffers>`_.
