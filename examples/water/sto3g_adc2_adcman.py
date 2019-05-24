#!/usr/bin/env python3
## vi: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
from import_data import import_data

import adcc

from adcc.solver.adcman import jacobi_davidson

# Gather preliminary data and import it into an HfData object
data = import_data()

# Setup the matrix
matrix = adcc.AdcMatrix("adc2", adcc.ReferenceState(data))

# Solve for 3 singlets and 3 triplets with some default output
states = jacobi_davidson(matrix, print_level=100, n_singlets=3, n_triplets=3)
print(states[0].describe())
print(states[1].describe())
