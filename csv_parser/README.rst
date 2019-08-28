About
=====

This subproject provides CSV (Comma Separated Value) parser.

CSV consists from:

* cells (word or phrase within double quotes);
* rows (a group of cells separated by comma);
* several rows separated by new line (complete CSV);
* (optional) header - the first row.

To simplify creation of CSV object it is provided ``load_from_string`` function
and ``_csv`` string literal suffix.

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

Pass all tests.
