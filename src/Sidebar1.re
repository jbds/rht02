

let s2e = React.string;

// let doCardDeals = (dispatch) => {
//   dispatch(Deal);
// }

[@react.component]
let make = (~dispatch: Global.action => unit, ~state: Shuffle.state) => {
  let isNotShuffled = Array.length(state.cardsNorth) == 0 ? true : false;
  let do52CardDeals = (dispatch: Global.action => unit) => {
    for (x in 0 to 51) {
      let _ = Js.Global.setTimeout(() => dispatch(Deal), 60 * x);
    }
  };
  <div>
    <button 
    onClick=((_e) => dispatch(Shuffle)) //Js.log("Cicked LogToConsole"))//
    style=(
      ReactDOMRe.Style.make(
        ~color={"#404040"}, 
        ~fontSize={"2.5vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Shuffle"))
    </button>
    <br/>
    <label
    style=(
      ReactDOMRe.Style.make(
        ~color={isNotShuffled ? "#C0C0C0" : "#404040"}, 
        ~fontSize={"2.5vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Dealer: "))
    </label>
    <select 
    onChange=((e) => dispatch(DealerChange(ReactEvent.Form.target(e)##value))) //Js.log("Dealer selected"))
    style=(
      ReactDOMRe.Style.make(
        ~color={isNotShuffled ? "#C0C0C0" : "#404040"}, 
        ~fontSize={"2.5vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    disabled=isNotShuffled
    >
      <option value="?">(s2e("?"))</option>
      <option value="N">(s2e("N"))</option>
      <option value="E">(s2e("E"))</option>
      <option value="S">(s2e("S"))</option>
      <option value="W">(s2e("W"))</option>
    </select>
    <br/>
    <button 
    onClick=((_e) => {do52CardDeals(dispatch)}) //Js.log("Cicked LogToConsole"))//
    style=(
      ReactDOMRe.Style.make(
        ~color={state.dealer == None ? "#C0C0C0" : "#404040"}, 
        ~fontSize={"2.5vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    disabled={state.dealer == None ? true : false}
    >
      (s2e("Deal"))
    </button>
    <br/>
  </div>
};
