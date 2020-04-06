let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit) => {
  <div>
    <button 
    onClick=((_e) => dispatch(AddItem)) //Js.log("Cicked Test"))//dispatch(AddItem))
    style=(
      ReactDOMRe.Style.make(
        ~color={"Red"}, 
        ~fontSize={"3vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Test"))
    </button>
    <button 
    onClick=((_e) => dispatch(LogToConsole)) //Js.log("Cicked LogToConsole"))//
    style=(
      ReactDOMRe.Style.make(
        ~color={"Green"}, 
        ~fontSize={"3vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Log to Console"))
    </button>
  </div>
};
