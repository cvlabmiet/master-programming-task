О задании
=========

Предоставление потокобезопасной прокси обёртки.

Требования
==========

Используйте наследование, а не аггрегацию.

Обязательно прохождение всех тестов.

Подсказки
=========

#. Оператор ``operator->`` является рекурсивным: можно возвращать объект с ``operator->``, который возвращает объект с ``operator->`` и т.д.
#. ``std::lock_guard`` совместим с концепцией RAII.
#. При вызове конструктора базового класса можно не писать шаблонные параметры и пространство имён, указав только вложенность ``proxy::``.
