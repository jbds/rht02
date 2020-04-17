let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit, ~location: Ute.location) => {
  <div>
    <button 
    onClick=((_e) =>  dispatch(Flip (location))) //Js.log("Flip action trace location: " ++ location))
    style=(
      ReactDOMRe.Style.make(
        ~color={"Black"}, 
        ~fontSize={"2vh"},
        ~marginTop={"1vh"},
        ~marginLeft={"-3vh"},
        ()
      )
    )
    >
      (s2e("Flip"))
    </button>
  </div>
};
