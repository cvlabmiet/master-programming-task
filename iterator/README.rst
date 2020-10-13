About
=====

This subproject provides 2D-iterator over linear pointer of image data.

Requirements
============

Use dedicated methods of ``boost::iterator_adaptor``: ``increment``, ``decrement``, ``advance``, ``distance_to``.

Pass all tests.

Hints
=====

#. Use a couple of base iterators:

   * the first is for the beginning of a row;
   * the second is an absolute linear iterator of an image.

#. Remember that ``index = row * stride + col``, and ``row = [index / stride]`` and ``col = index % stride``.
   Your inner iterator is equivalent to ``index``.
#. It is enough to implement only ``advance`` method.
#. Your iterator should skip gap between ``width`` and ``stride``, so skip the delta ``stride - width``.
