About
=====

This subproject provides 2D-iterator over linear pointer of image data.

Requirements
============

Use a couple of base iterators:

* the first is for the beginning of a row;
* the second is absolute linear iterator of an image.

Use dedicated methods of ``boost::iterator_adaptor``: ``advance``, ``increment``, ``dereference``, and so on.

Pass all tests.
