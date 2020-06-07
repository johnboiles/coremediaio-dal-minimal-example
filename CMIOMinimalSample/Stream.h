//
//  Stream.h
//  CMIOMinimalSample
//
//  Created by John Boiles  on 4/10/20.
//
//  CMIOMinimalSample is free software, and use is bound by the terms
//  set out in the LICENSE file distributed with this project.

#import <Foundation/Foundation.h>

#import "ObjectStore.h"

NS_ASSUME_NONNULL_BEGIN

@interface Stream : NSObject <CMIOObject>

@property CMIOStreamID objectId;

- (instancetype _Nonnull)init;

- (CMSimpleQueueRef)copyBufferQueueWithAlteredProc:(CMIODeviceStreamQueueAlteredProc)alteredProc alteredRefCon:(void *)alteredRefCon;

- (void)startServingFrames;

- (void)stopServingFrames;

@end

NS_ASSUME_NONNULL_END
