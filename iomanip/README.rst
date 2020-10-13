About
=====

This subproject describes input/output manipulators for ``std::stream`` objects.

Requirements
============

Pass all tests.

Hints
=====

#. iostream can call functions with ``std::ostream&(std::ostream&)`` signatures.
#. You can provide overloaded ``std::ostream& operator<<(std::ostream&, YourClass)`` to print content of ``YourClass``.
#. To avoid global objects (function or variable) use ``inline`` keyword.
#. Apply friend ``operator <<`` to your classes.
#. You can return some specific object with overloaded ``operator <<`` from outer structure`s ``operator <<``.
#. Be careful: return ``std::ostream&`` by reference, but your wrappers should be returned by value.
#. Use type provided by template to apply operation ``+``.
