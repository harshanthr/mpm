#ifndef MPM_MPM_H_
#define MPM_MPM_H_

#include <memory>
#include <vector>

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "io.h"
#include "mesh.h"
#include "read_mesh.h"
#include "read_mesh_ascii.h"
#include "vtk_writer.h"

namespace mpm {
//! MPM class
//! \brief MPM class calls solver and algorithm
//! \details MPM class: implicit and explicit MPM
class MPM {
 public:
  //! Constructor
  MPM(std::unique_ptr<IO>&& io) : io_(std::move(io)) {
    // Unique id
    uuid_ =
        boost::lexical_cast<std::string>(boost::uuids::random_generator()());
  }

  // Initialise mesh and particles
  virtual bool initialise_mesh_particles() = 0;

  // Initialise materials
  virtual bool initialise_materials() = 0;

  // Solve
  virtual bool solve() = 0;

  //! Write VTK files
  virtual void write_vtk(mpm::Index step, mpm::Index max_steps) = 0;

  //! Write HDF5 files
  virtual void write_hdf5(mpm::Index step, mpm::Index max_steps) = 0;

 protected:
  //! A unique id for the analysis
  std::string uuid_;
  //! Time step size
  double dt_{std::numeric_limits<double>::max()};
  //! Number of steps
  mpm::Index nsteps_{std::numeric_limits<mpm::Index>::max()};
  //! A unique ptr to IO object
  std::unique_ptr<mpm::IO> io_;
  //! JSON analysis object
  Json analysis_;
  //! Logger
  std::shared_ptr<spdlog::logger> console_;
};
}  // namespace mpm

#endif  // MPM_MPM_H_
