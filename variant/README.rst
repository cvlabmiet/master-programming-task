About
=====

This subproject shows an application of ``variant`` concept.

Requirements
============

Do not mix up different implementations.
All recursive cases should depend only on themselves.

Pass all tests.

Hints
=====

#. Learn ``std::variant`` and ``std::get(std::variant)``.
#. Actively use ``using`` to pull constructors from base class, i.e. ``using vector::vector;``.
#. You can use ``std::shared_ptr`` and ``boost::recursive_wrapper`` to achieve type recursion.
#. ``constexpr`` is your friend.
#. ``std::disjunction_v`` is like an operator ``||``.
#. Method ``as`` works like ``std::get``.
#. `Reuse your code <https://stackoverflow.com/questions/123758/how-do-i-remove-code-duplication-between-similar-const-and-non-const-member-func>`_.
#. Use previously implemented ``variant_decorator`` for ``recursive_map``.
