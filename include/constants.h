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
    FOUND_BLACKSMITH,
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
// enum TextStyle {
//     TROLL = fmt::emphasis::bold | fg(fmt::color::purple),
//     SPHINX = fmt::emphasis::bold | fg(fmt::color::gold),
//     BLACKSMITH = fmt::emphasis::bold | fg(fmt::color::teal),
//     FAIRY = fmt::emphasis::bold | fg(fmt::color::pink),
//     ANCIENT_DOOR = fmt::emphasis::bold | fg(fmt::color::rosy_brown),
//     BAD_EVENT = fmt::emphasis::italic | fg(fmt::color::orange),
//     GOOD_EVENT = fmt::emphasis::italic | fg(fmt::color::green),
//     GAME_OVER = fmt::emphasis::bold | fg(fmt::color::red),
//     CHAPTER = fmt::emphasis::bold | fg(fmt::color::green_yellow),
// };


// Collection of text stylers that can be used with the fmt::print
// command to pretty up text.
/*
const vector<Style> styles {

}
*/


#endif // end of "header guard" for __CONSTANTS_H__
