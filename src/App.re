open Global;

[@react.component]
let make = () => {
  // 'dispatch' will not change between re-renders
  // useReducer expects to have passed in a reducer function and an initial state
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <div id={"main"}>
    // SOUTH CARD
    <div>
      (
        ReasonReact.array(
          Array.map(
            ((index, (filePath, lc))) =>
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=50.0
                topVh=75.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
                isFlipSide=state.southIsFlipped
                lifecycle=lc
              />
              ,
              state.cardsSouth
          )
        )
      )
    </div>
    // SOUTH FLIP 
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"90%"}, 
          ~left={"50%"}, 
          ()
        )
      )
    >
      <FlipButton dispatch location=South/>
    </div>
    // WEST CARD
    <div>
      (
        ReasonReact.array(
          Array.map(
            ((index, (filePath, lc))) =>
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=25.0
                topVh=50.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
                isFlipSide=state.westIsFlipped
                lifecycle=lc
              />
              ,
              state.cardsWest
          )
        )
      )
    </div> 
    // WEST FLIP
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"65%"}, 
          ~left={"25%"}, 
          ()
        )
      )
    >
      <FlipButton dispatch location=West/>
    </div>
    // NORTH CARD
    <div>
      (
        ReasonReact.array(
          Array.map(
            ((index, (filePath, lc))) =>
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=50.0
                topVh=25.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
                isFlipSide=state.northIsFlipped
                lifecycle=lc
              />
              ,
              state.cardsNorth
          )
        )
      )
    </div> 
    // NORTH FLIP 
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"40%"}, 
          ~left={"50%"}, 
          ()
        )
      )
    >
      <FlipButton dispatch location=North/>
    </div>
    // EAST CARD
    <div>
      (
        ReasonReact.array(
          Array.map(
            ((index, (filePath, lc))) =>
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=75.0
                topVh=50.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
                isFlipSide=state.eastIsFlipped
                lifecycle=lc
              />
              ,
              state.cardsEast
          )
        )
      )
    </div> 
    // <div>
    //           <PlayingCardRotatable 
    //             key={string_of_int(0)}
    //             cardIndex=0
    //             filePath={"./images/" ++ "JD" ++ ".svg"}
    //             leftVw=75.0
    //             topVh=50.0
    //             parentElementWidthPx={[%raw {| window.innerWidth |}]} 
    //             parentElementHeightPx={[%raw {| window.innerHeight |}]}
    //             isFlipSide=state.eastIsFlipped
    //             lifecycle=Dealer
    //           />
    // </div>  
    // EAST FLIP 
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"65%"}, 
          ~left={"75%"}, 
          ()
        )
      )
    >
      <FlipButton dispatch location=East/>
    </div>
    // SIDEBARS
    <div id="sidebar1">
      <Sidebar1 dispatch/>
    </div>
    <div id="sidebar2">
      //(s2e("Sidebar2"))
    </div>
    <div id="sidebar3">
      //(s2e("Sidebar3"))
      <Sidebar3 dispatch/>
    </div>
  </div>
};