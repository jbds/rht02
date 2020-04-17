let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit) => {
  <div>
    <button 
    onClick=((_e) => dispatch(Shuffle)) //Js.log("Cicked LogToConsole"))//
    style=(
      ReactDOMRe.Style.make(
        ~color={"Green"}, 
        ~fontSize={"2vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Shuffle"))
    </button>
  </div>
};
