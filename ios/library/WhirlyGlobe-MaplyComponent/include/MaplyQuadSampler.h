/*
 *  MaplyQuadSampler.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 3/27/18.
 *  Copyright 2011-2018 Saildrone Inc
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import "MaplyViewControllerLayer.h"
#import "MaplyCoordinateSystem.h"
#import "MaplyTileSource.h"
#import "MaplyRenderController.h"

/**
    Sampling parameters.
 
    These are used to describe how we want to break down the globe or
    flat projection onto the globe.
  */
@interface MaplySamplingParams : NSObject

/// The coordinate system we'll be sampling from.
@property (nonatomic,nonnull) MaplyCoordinateSystem *coordSys;

/// Min zoom level for sampling
@property (nonatomic) int minZoom;

/// Max zoom level for sampling
@property (nonatomic) int maxZoom;

/// Cutoff for loading tiles.  This is size in screen space (pixels^2)
@property (nonatomic) double minImportance;

/// Normally we always load the lowest level
/// If this is set we only load those lowest level tiles that pass this test
@property (nonatomic) double minImportanceTop;

/// Generate geometry to cover the north and south poles
/// Only works for world-wide projections
@property (nonatomic) bool coverPoles;

/// If set, generate skirt geometry to hide the edges between levels
@property (nonatomic) bool edgeMatching;

/// Tesselation values per level for breaking down the coordinate system (e.g. globe)
@property (nonatomic) int tessX,tessY;

/// If set, we'll try to load a single level
@property (nonatomic) bool singleLevel;

/// If set, the tiles are clipped to this boundary
@property (nonatomic) MaplyBoundingBoxD clipBounds;
@property (nonatomic,readonly) bool hasClipBounds;

/**
 Detail the levels you want loaded in target level mode.
 
 The layer calculates the optimal target level.  The entries in this array are relative to that level or absolute.  For example [0,-4,-2] means the layer will always try to load levels 0, targetLevel-4 and targetLevel-2, but only the latter two if they make sense.
 */
@property (nonatomic,nullable) NSArray *levelLoads;

/// Decide if these sampling params are the same as others
- (bool)isEqualTo:(MaplySamplingParams *__nonnull)other;

@end
