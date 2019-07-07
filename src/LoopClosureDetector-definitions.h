/* ----------------------------------------------------------------------------
 * Copyright 2017, Massachusetts Institute of Technology,
 * Cambridge, MA 02139
 * All Rights Reserved
 * Authors: Luca Carlone, et al. (see THANKS for the full author list)
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 * @file   LoopClosureDetector-definitions.h
 * @brief  Definitions for LoopClosureDetector
 * @author Marcus Abate
 */

 #pragma once

#include "common/vio_types.h"

namespace VIO {

struct LoopClosureDetectorInputPayload {
  LoopClosureDetectorInputPayload(const Timestamp& timestamp_kf,
                                  const StereoFrame stereo_frame)
    : timestamp_kf_(timestamp_kf),
      stereo_frame_(stereo_frame) {}

  const Timestamp timestamp_kf_;
  const StereoFrame stereo_frame_;

}; // struct LoopClosureDetectorInputPayload

// TODO: Add transform between the two frames
struct LoopClosureDetectorOutputPayload {
  LoopClosureDetectorOutputPayload(bool is_loop,
                                   const Timestamp& timestamp_kf,
                                   const FrameId& id_recent,
                                   const FrameId& id_match,
                                   const gtsam::Pose3& relative_pose)
    : is_loop_(is_loop),
      timestamp_kf_(timestamp_kf),
      id_recent_(id_recent),
      id_match_(id_match),
      relative_pose_(relative_pose) {}

  // TODO: inlude score of match
  const bool is_loop_;
  const Timestamp timestamp_kf_;
  const FrameId id_recent_;
  const FrameId id_match_;
  const gtsam::Pose3 relative_pose_;
}; // struct LoopClosureDetectorOutputPayload

} // namespace VIO
