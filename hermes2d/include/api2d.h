// This file is part of Hermes2D
//
// Copyright (c) 2009 hp-FEM group at the University of Nevada, Reno (UNR).
// Email: hpfem-group@unr.edu, home page: http://hpfem.org/.
//
// Hermes2D is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
//
// Hermes2D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hermes2D; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
/*! \file api.h
\brief Main Hermes API
*/
#ifndef __HERMES_API_2D_H_
#define __HERMES_API_2D_H_
// This is here because of an operator-related error in gcc
#pragma GCC diagnostic warning "-fpermissive"

#include "compat.h"
#include "hermes_common.h"

namespace Hermes
{
  namespace Hermes2D
  {
    class Mesh;
    template<typename Scalar> class Space;
    template<typename Scalar> class Solution;

    /// Enumeration of potential keys in the Api2D::parameters storage.
    enum Hermes2DApiParam
    {
      numThreads,
      secondDerivatives
    };


    /// Class for calculating pointers of instance T.
    template<typename T>
    class HERMES_API PointerCalculator
    {
    public:
      PointerCalculator();
      unsigned int getNumber() const;
    private:
      void operator+(unsigned int increaseBy);
      void operator++();
      void operator-(unsigned int decreaseBy);
      void operator--();
      unsigned int count;
      friend class Mesh;
      template<typename T1> friend class Space;
      template<typename T1> friend class Solution;
    };

    /// API Class containing settings for the whole Hermes2D.
    class HERMES_API Api2D
    {
    public:
      Api2D();
      ~Api2D();
    protected:
      /// Parameter class, representing one parameter.
      /// Its identifier is a string identifier according to which, the instance is inserted into Api2D::parameters.
      class HERMES_API Parameter
      {
      public:
        /// Constructor.
        /// \param[in] default_val Default value, if the user does not specify his own.
        Parameter(int default_val);
        bool user_set;
        int user_val;
        int default_val;
      };

      /// The storage of parameters.
      /// This storage is not optimized for speed, but for comfort of users.
      /// There should not be any parameters, values of which are sought very often, because of the above reason.

      std::map<Hermes2DApiParam, Parameter*> parameters;
    public:
      int get_param_value(Hermes2DApiParam);
      void set_param_value(Hermes2DApiParam, int value);

      unsigned int getNumberMeshPointers() const;
      unsigned int getNumberSpacePointers() const;
      unsigned int getNumberRealSpacePointers() const;
      unsigned int getNumberComplexSpacePointers() const;
      unsigned int getNumberSolutionPointers() const;
      unsigned int getNumberRealSolutionPointers() const;
      unsigned int getNumberComplexSolutionPointers() const;

    private:
      PointerCalculator<Mesh> meshPointerCalculator;
      PointerCalculator<Space<double> > realSpacePointerCalculator;
      PointerCalculator<Space<std::complex<double> > > complexSpacePointerCalculator;
      PointerCalculator<Solution<double> > realSolutionPointerCalculator;
      PointerCalculator<Solution<std::complex<double> > > complexSolutionPointerCalculator;
      friend class Mesh;
      template<typename T1> friend class Space;
      template<typename T1> friend class Solution;
    };

    /// Global instance used inside Hermes which is also accessible to users.
    extern HERMES_API Hermes::Hermes2D::Api2D Hermes2DApi;
  }
}
#endif