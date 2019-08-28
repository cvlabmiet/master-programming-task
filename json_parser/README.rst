About
=====

This subproject provides json parser.

Json is a recursive format used to store data.
Types of json include:

* primitive types: boolean, number, string, null;
* arrays that contain different types;
* key-value pairs (object), where key is always string.

Each part of parser has own name space.
This is alternative to classes with methods.
It is a common practice for the ``boost::spirit::x3``.

Requirements
============

Implement ``parser_helper``.

Describe types.
They should be simple, std-containers is enough.

Describe rules.
You should use parser types created on the previous step.

Define rules.
Recurrent rules can be defined separately.

Pass all tests.
