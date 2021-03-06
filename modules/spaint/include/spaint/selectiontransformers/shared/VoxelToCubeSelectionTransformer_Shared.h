/**
 * spaint: VoxelToCubeSelectionTransformer_Shared.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#ifndef H_SPAINT_VOXELTOCUBESELECTIONTRANSFORMER_SHARED
#define H_SPAINT_VOXELTOCUBESELECTIONTRANSFORMER_SHARED

#include <ITMLib/Utils/ITMLibDefines.h>

namespace spaint {

/**
 * \brief Writes a voxel to the output selection.
 *
 * \param outputVoxelIndex  The index in the output selection at which to write the voxel.
 * \param cubeSideLength    The length of each side of one of the cubes (in voxels).
 * \param cubeSize          The number of voxels in each cube.
 * \param radius            The (Manhattan) radius (in voxels) to select around each initial voxel.
 * \param inputSelection    The input selection of voxels.
 * \param outputSelection   The output selection of voxels.
 */
_CPU_AND_GPU_CODE_
inline void write_voxel_to_output_selection(int outputVoxelIndex, int cubeSideLength, int cubeSize, int radius, const Vector3s *inputSelection, Vector3s *outputSelection)
{
  // Look up the input voxel that corresponds to this output voxel (there is one input voxel for each cube of output voxels).
  int inputVoxelIndex = outputVoxelIndex / cubeSize;
  const Vector3s& inputVoxel = inputSelection[inputVoxelIndex];

  // Calculate the linear offset of the output voxel within its cube.
  int offset = outputVoxelIndex % cubeSize;

  // Use this linear offset to calculate the 3D offset of the output voxel from the position of the input voxel.
  int xOffset = offset % cubeSideLength - radius;
  int yOffset = offset % (cubeSideLength * cubeSideLength) / cubeSideLength - radius;
  int zOffset = offset / (cubeSideLength * cubeSideLength) - radius;

  // Write the output voxel to the output selection.
  outputSelection[outputVoxelIndex] = Vector3s(inputVoxel.x + xOffset, inputVoxel.y + yOffset, inputVoxel.z + zOffset);
}

}

#endif
