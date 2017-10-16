#include <cstdlib>    // atoi
#include <iostream>
#include <string>
#include "../term-react/src/term-react/term-react.hpp"
#include "../term-react/src/term-react/termbox/termbox.cpp"
#include "../term-react/src/term-react/termbox/utf8.cpp"
#include "../term-react/src/term-react/dangerous-pretty-macros.h"

namespace tr = termreact;

InitReducer(locationReducer, () { return "/"; });

enum class HomeMenu {
  DataStructure,
  Sorting,
  Searching,
  Maths
};

enum class HomeAction {
  Select
};

InitReducer(homeReducer, () { return HomeMenu::DataStructure; });
Reducer(homeReducer, (HomeAction::Select), (HomeMenu, HomeMenu selected) {
  return selected;
});

DeclareStore(Store,
  (std::string, location, locationReducer)
  (HomeMenu, homeSelected, homeReducer)
);

ComponentClass(App) {
  DeclareProps(
    (std::string, location)
    (HomeMenu, selected)
  );

  MapStoreStateToProps(
    (location, State(location))
    (selected, State(homeSelected))
  );

  Render() {
    Component(tr::Box, Attr()) {
      Component(tr::Box, "Nav", Attr(
        (getHeight, [] (int, int h) { return h / 20;})
        (border_bottom, 0x2594)
      )) {
        Component(tr::Box, "BackButton", Attr(
          (getWidth, [] (int w, int) { return w / 5; })
          (text, "<<= BACK")
          (border_right, 0x258F)
        )) { NoChildren };
        Component(tr::Box, "Location", Attr(
          (getLeft, [] (int w, int) { return w / 5; })
          (getWidth, [] (int w, int) { return w - w / 5; })
          (text, Props(location) == "/" ? "Home" : "Unknown")
        )) { NoChildren };
      };
      if (Props(location) == "/") {
        Component(tr::Box, "Home", Attr(
          (getTop, [] (int, int h) { return h / 20 + 5;})
          (getWidth, [] (int w, int) { return w / 5; })
          (getLeft, [] (int w, int) { return (w - w / 5) / 2; })
        )) {
          Component(tr::Box, "DataStructure", Attr(
            (text, "Data Structure")
            (top, 0)
            (height, 5)
            (focusable, true)
            (onFocus, [this] () { Dispatch(HomeAction::Select)(HomeMenu::DataStructure); })
            (border, Props(selected) == HomeMenu::DataStructure ? '*' : '+')
            (frontground, Props(selected) == HomeMenu::DataStructure ? TB_BOLD | TB_UNDERLINE : TB_DEFAULT)
          )) { NoChildren};
          Component(tr::Box, "Sorting", Attr(
            (text, "Sorting")
            (top, 10)
            (height, 5)
            (focusable, true)
            (onFocus, [this] () { Dispatch(HomeAction::Select)(HomeMenu::Sorting); })
            (border, Props(selected) == HomeMenu::Sorting ? '*' : '+')
            (frontground, Props(selected) == HomeMenu::Sorting ? TB_BOLD | TB_UNDERLINE : TB_DEFAULT)
          )) { NoChildren};
          Component(tr::Box, "Searching", Attr(
            (text, "Searching")
            (top, 20)
            (height, 5)
            (focusable, true)
            (onFocus, [this] () { Dispatch(HomeAction::Select)(HomeMenu::Searching); })
            (border, Props(selected) == HomeMenu::Searching ? '*' : '+')
            (frontground, Props(selected) == HomeMenu::Searching ? TB_BOLD | TB_UNDERLINE : TB_DEFAULT)
          )) { NoChildren};
          Component(tr::Box, "Maths", Attr(
            (text, "Maths")
            (top, 30)
            (height, 5)
            (focusable, true)
            (onFocus, [this] () { Dispatch(HomeAction::Select)(HomeMenu::Maths); })
            (border, Props(selected) == HomeMenu::Maths ? '*' : '+')
            (frontground, Props(selected) == HomeMenu::Maths ? TB_BOLD | TB_UNDERLINE : TB_DEFAULT)
          )) { NoChildren};
        };
      }
    };
  }

public:
  ComponentWillMount(App) {}
  ComponentWillUnmount(App) {}
  ComponentWillUpdate(next_props) {}
};

int main(int argc, char* argv[]) {
  Store store;
  tr::Termbox tb{store, TB_OUTPUT_NORMAL};

  tb.render<App>(store, [] (const Store::StateType &state) {
    return false;
  });
  tb.runMainLoop();
  return 0;
}
