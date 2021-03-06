//
//  SFSubtitleParseService.h
//  SubPlayerTest
//
//  Created by Jack on 1/2/13.
//  Copyright (c) 2013 Clunet. All rights reserved.
//

#import <Foundation/Foundation.h>

//------------------------------------------------------------------------------
@interface SFSubtitleParserService: NSObject
/// Parse the subtitle from url and return an array of `SFSubtitleTrack`
/**
 Create an array of subtitle track from from a given url
 @param url subtitle file location
 @param langcode the ISO language code, that is a hint about language contain in subtile file
 
 @return Array of subtitle tracks
 @discussion
 For some subtitle file format that support mutil tracks (such as smi) each track usually contains information about it language.
 For subtitle format that dont, there maybe no language information, `languageCode` will give the hint about what language the subtilte in.
 
 This function will autodetect the language, the detected language may different from the hint. In that case, the detected language will be used. 
 */
+ (NSArray*) subtitleTracksFromContentURL: (NSURL*) url
                             languageHint: (NSString*) langCode;
@end

//------------------------------------------------------------------------------
@protocol SFSubtitleParser <NSObject>
@required
/**
 Parse the subtitle content from `content` and return subtitle tracks
 @param content a string contains content of subtitle file.
 @param lang ISO language code, used as reference if there is no information
 about what language the subtitle is of (Subrip subtitle case)
 */
- (NSArray*) tracksFromContentString: (NSString*) content
                      preferLanguage: (NSString*) lang;
@optional
- (NSArray*) tracksFromContentURL: (NSURL*) url;

@end