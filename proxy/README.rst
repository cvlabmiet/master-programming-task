About
=====

This subproject provides proxy wrapper with synchronization.

Requirements
============

Try to use inheritance, not aggregation.

Pass all tests.

Hints
=====

#. ``operator ->`` is recursive: you can return object with ``operator ->`` that returns object with ``operator ->`` and so on.
#. Hint: ``std::lock_guard`` comply with RAII concept.
