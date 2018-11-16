/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * INTEL CONFIDENTIAL
 *
 * Copyright (c) 2018 Intel Corporation
 *
 * This software and the related documents are Intel copyrighted materials, and
 * your use of them is governed by the express license under which they were
 * provided to you (License). Unless the License provides otherwise, you may not
 * use, modify, copy, publish, distribute, disclose or transmit this software or
 * the related documents without Intel's prior written permission.
 *
 * This software and the related documents are provided as is, with no express or
 * implied warranties, other than those that are expressly stated in the License.
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * @file
 *
 */

#pragma once
#include <limits>

#include <string>
#include <vector>
#include "rss/time/TimeIndex.hpp"
#include "rss/world/Object.hpp"
#include "rss/world/Scene.hpp"
/*!
 * @brief namespace rss
 */
namespace rss {
/*!
 * @brief namespace world
 */
namespace world {

struct WorldModel
{
  ::rss::time::TimeIndex timeIndex{0u};
  ::rss::world::Object egoVehicle;
  std::vector<::rss::world::Scene> scenes;
};

/*
 * \brief Event to support type within statecharts
 */
struct evRssWorldModel
{
  evRssWorldModel(WorldModel const &worldModel)
    : worldModel(worldModel)
  {
  }

  WorldModel const &data() const
  {
    return worldModel;
  }

  WorldModel const &worldModel;
};

} // namespace world
} // namespace rss

/*!
 * @brief Conversion of event evRssWorldModel to std::string (for logging purposes)
 */
std::string toString(::rss::world::evRssWorldModel const &);