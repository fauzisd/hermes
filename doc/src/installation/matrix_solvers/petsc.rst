PETSc
-----

.. _PETSc home page: http://www.mcs.anl.gov/petsc/
.. _solvers repository: https://github.com/hpfem/solvers
.. _manual: https://github.com/hpfem/solvers/raw/master/manuals/petsc.pdf

Linux
~~~~~

Using standard Debian packages
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Install packages `libpetsc3.1` and `libpetsc3.1-dev`. 
Newer version may be available. In Ubuntu 6.06 (Dapper)
or newer, you can use the Synaptic package manager for that, or type::

   sudo apt-get install libpetsc3.1 libpetsc3.1-dev

Now go to the directory with Hermes. Create the file CMake.vars with the
following line (or append to the existing one)::

  set(WITH_PETSC YES)

Finally execute::
  
  rm CMakeCache.txt
  cmake .
  make

Find more about :ref:`ref-usage-petsc`.

Windows MSVC
~~~~~~~~~~~~

http://www.mcs.anl.gov/petsc/petsc-as/documentation/installation.html#Windows

Mac OS
~~~~~~

http://petsc.darwinports.com/

.. _ref-usage-petsc:

Using PETSC in Hermes
~~~~~~~~~~~~~~~~~~~~~

You may now select ``SOLVER_PETSC`` as the matrix solver for your finite element problem, as detailed
in the `Poisson tutorial <http://hpfem.org/hermes/doc/src/hermes2d/P01-linear/03-poisson.html>`__, or use
it just to solve a standalone matrix problem :math:`Ax = b` as in the 
`Using Matrix Solvers tutorial <http://hpfem.org/hermes/doc/src/hermes2d/P08-miscellaneous/35-matrix-solvers.html>`__.
