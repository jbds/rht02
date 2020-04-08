
let s2e = React.string;
let initialState: Shuffle.state = {dealerPlus1: [||], dealerPlus2: [||], dealerPlus3: [||], dealerPlus0: [||]};

[@react.component]
let make = () => {
  // 'dispatch' will not change between re-renders
  // useReducer expects to have passed in a reducer function and an initial state
  let (state, dispatch) = React.useReducer(Global.reducer, initialState);

  //let cardsDealerPlus0Qty = List.length(cardsDealerPlus0);
  
  <div id={"main"}>
    <div>
      (
        React.array(
            Array.map(
              ((index, filePath)) => 
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=50.0
                topVh=75.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
              />
              , 
              state.dealerPlus1
            )
        )
      ) 
    </div>   
    <div>
      (
        React.array(
            Array.map(
              ((index, filePath)) => 
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=25.0
                topVh=50.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
              />
              , 
              state.dealerPlus2
            )
        )
      ) 
    </div>   
    <div>
      (
        React.array(
            Array.map(
              ((index, filePath)) => 
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=50.0
                topVh=25.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
              />
              , 
              state.dealerPlus3
            )
        )
      ) 
    </div>  
    <div>
      (
        React.array(
            Array.map(
              ((index, filePath)) => 
              <PlayingCardRotatable 
                key={string_of_int(index)}
                cardIndex=index
                filePath={"./images/" ++ filePath ++ ".svg"}
                leftVw=75.0
                topVh=50.0
                parentElementWidthPx={[%raw {| window.innerWidth |}]} 
                parentElementHeightPx={[%raw {| window.innerHeight |}]}
              />
              , 
              state.dealerPlus0
            )
        )
      ) 
    </div>   
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"15%"}, 
          ~left={"50%"}, 
          ()
        )
      )
    >
      //(s2e(string_of_int(cardsDealerPlus0Qty)))
      (s2e("N"))
    </div>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"85%"}, 
          ~left={"50%"}, 
          ()
        )
      )
    >
      (s2e("S"))
    </div>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"50%"}, 
          ~left={"15%"}, 
          ()
        )
      )
    >
      (s2e("W"))
    </div>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~position={"absolute"}, 
          ~top={"50%"}, 
          ~left={"85%"}, 
          ()
        )
      )
    >
      (s2e("E"))
    </div>
    <div id="sidebar1">
      <Sidebar1 dispatch/>
    </div>
    <div id="sidebar2">(s2e("Sidebar2"))</div>
    <div id="sidebar3">(s2e("Sidebar3"))</div>
  </div>
};