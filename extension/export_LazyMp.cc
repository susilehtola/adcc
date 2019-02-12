//
// Copyright (C) 2018 by the adcc authors
//
// This file is part of adcc.
//
// adcc is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// adcc is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with adcc. If not, see <http://www.gnu.org/licenses/>.
//

#include <adcc/LazyMp.hh>
#include <adcc/ReferenceState.hh>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace adcc {
namespace py_iface {

void export_LazyMp(py::module& m) {
  py::class_<LazyMp, std::shared_ptr<LazyMp>>(
        m, "LazyMp",
        "Class representing information about the Mo/ller-Plesset results from ADCman.")
        .def(py::init<std::shared_ptr<const ReferenceState>>())
        .def("energy_correction", &LazyMp::energy_correction,
             "Obtain the appropriate MP energy correction.")
        .def("df", &LazyMp::df, "Obtain the Delta Fock matrix.")
        .def("t2", &LazyMp::t2, "Obtain the T2 amplitudes.")
        .def("td2", &LazyMp::td2, "Obtain the T^D_2 term.")
        .def_property_readonly("mp2_diffdm", &LazyMp::mp2_diffdm_ptr,
                               "Obtain the MP2 difference density object.")
        .def_property_readonly("reference_state", &LazyMp::reference_state_ptr)
        .def_property_readonly("has_core_valence_separation",
                               &LazyMp::has_core_valence_separation)
        //
        ;
}

}  // namespace py_iface
}  // namespace adcc