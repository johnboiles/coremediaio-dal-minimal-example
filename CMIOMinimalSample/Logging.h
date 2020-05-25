//
//  Logging.h
//  CMIOMinimalSample
//
//  Created by John Boiles  on 4/10/20.
//
//  CMIOMinimalSample is free software, and use is bound by the terms
//  set out in the LICENSE file distributed with this project.

#ifndef Logging_h
#define Logging_h

#define DLog(fmt, ...) NSLog((@"CMIOMS: " fmt), ##__VA_ARGS__)
#define DLogFunc(fmt, ...) NSLog((@"CMIOMS: %s " fmt), __FUNCTION__, ##__VA_ARGS__)

#endif /* Logging_h */
