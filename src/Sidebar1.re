let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit) => {
  <div>
    <button 
    onClick=((_e) => dispatch(Action1)) //Js.log("Cicked Test"))//dispatch(Action1))
    style=(
      ReactDOMRe.Style.make(
        ~color={"Red"}, 
        ~fontSize={"3vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Action1"))
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
      (s2e("Action2"))
    </button>
  </div>
};
