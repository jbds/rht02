let s2e = React.string;

[@react.component]
let make = (~dispatch: Global.action => unit, ~location: string) => {
  <div>
    <button 
    onClick=((_e) =>  Js.log("Flip action trace location: " ++ location))//dispatch(Action1)) //Js.log("Cicked Test"))//dispatch(Action1))
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
