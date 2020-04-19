

let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit, ~state: Shuffle.state) => {
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
        ~color={"#404040"}, 
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
        ~color={"#404040"}, 
        ~fontSize={"2.5vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      <option value="?">(s2e("?"))</option>
      <option value="N">(s2e("N"))</option>
      <option value="E">(s2e("E"))</option>
      <option value="S">(s2e("S"))</option>
      <option value="W">(s2e("W"))</option>
    </select>
    <br/>
    <button 
    onClick=((_e) => dispatch(Deal)) //Js.log("Cicked LogToConsole"))//
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
