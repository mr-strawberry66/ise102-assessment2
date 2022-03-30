/***************************************************
 * Constants
 ****************************************************************
 *
 * Place global constants in here: values that will be
 * used in various parts of your program. If they're
 * related, group them in an enum with a meaningful 
 * data type name like "Progress" or "GemType"
 ***************************************************/
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

enum Progress {
  NO_PROGRESS,
  HAVE_SILVER_ORE,
  HAVE_FORGED_KEY,
  HAVE_RUBY,
  HAVE_GEMMED_KEY,
  COMPLETED_GAME,
  FAILED
};

enum RedGem {
  UNIDENTIFIED_RED_GEM,
  GARNET,
  RUBY,
  TOURMALINE,
  RHODOLITE,
  SPINEL
};
// We'll talk about this one later
enum TextStyle { 
  TROLL = 0,
  STONE_DOOR,
  END_CHARACTERS 
};

// Collection of text stylers that can be used with the fmt::print
// command to pretty up text.
/*
const vector<Style> styles {
  
}
*/


#endif // end of "header guard" for __CONSTANTS_H__
