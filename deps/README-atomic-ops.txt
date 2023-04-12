This library was originally written with a dependency on libatomic_ops, which
is licensed under the GPL.

In this version, that has been replaced with simple macros that map
directly to the GCC built-in atomic operations
(https://gcc.gnu.org/onlinedocs/gcc/_005f_005fatomic-Builtins.html).

This works on some machines running macos and linux. On other systems you may
need to use libatomic_ops, if that license is usable for you.


