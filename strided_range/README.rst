About
=====

This subproject provides 2D-range over linear pointer of image data with stride.

Requirements
============

Code is done.
Write unit tests:

* Fixed width and dynamic stride.
  Two cases: stride is bigger than width, and smaller.
  Use the same data for all cases, ``SECTION`` may help.
* Fixed stride and dynamic width.
  The same approach described above.
* Stride is equal to width.
* Measure the size of the range.
  It should vary if stride is different.
* Create one strided range from another.
* Show how to create a window in the image with the help of strided range.
* Provide at least two corner cases that can lead to unambiguous/unpredictable behaviour.
