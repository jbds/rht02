let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit) => {
  <div>
    <button 
    onClick=((_e) => dispatch(HideAllCards)) //Js.log("Cicked Test"))
    style=(
      ReactDOMRe.Style.make(
        ~color={"Grey"}, 
        ~fontSize={"2vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Hide All Cards"))
    </button>
    <br/>
    <button 
    onClick=((_e) => dispatch(ShowAllCards)) //Js.log("Cicked Test"))
    style=(
      ReactDOMRe.Style.make(
        ~color={"Grey"}, 
        ~fontSize={"2vh"},
        ~marginTop={"1vh"},
        ()
      )
    )
    >
      (s2e("Show All Cards"))
    </button>
  </div>
};
