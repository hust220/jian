#pragma once

#ifdef JN_PARA

#include <string>
#include <memory>
#include "mpi.h"
#include "../utils/Env.hpp"

BEGIN_JN

void mpi_init(int *argc, char ***argv);

int mpi_rank();

int mpi_size();

void mpi_send();

Str mpi_recv();

void mpi_free();

END_JN

#endif
