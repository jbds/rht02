let cardHeightVh = 30.0;
let cardHeightOverCardWidth = 1.56;
let rotationOriginYOffsetMultiplier = 4.25;
let angleDeg = 3.75;
// use 6.0 for centre card upright, 7.5 looks better, but offsets catds to left
let cardIndexOffset = 0.0;
let baizeAsFractionOfViewportWidth = 0.8;
let f2s = Js.Float.toString;

[@react.component]
let make = 
  (
    ~cardIndex: int,
    ~filePath: string, 
    ~leftVw: float, 
    ~topVh: float, 
    ~parentElementWidthPx: float, 
    ~parentElementHeightPx: float,
  ) 
=> 
{
  let cardHalfWidthPx: float = parentElementHeightPx *. cardHeightVh /. (100.0 *. cardHeightOverCardWidth *. 2.0);
  //Js.log("cardHalfWidth=" ++ f2s(cardHalfWidthPx));
  // this adds offsets for baize width and card width
  let leftAdjustedVw: float = (leftVw  *. baizeAsFractionOfViewportWidth)  -. ((cardHalfWidthPx *. 100.0) /. (parentElementWidthPx));
  let cardHalfHeightPx: float = parentElementHeightPx *. cardHeightVh /. (100.0 *. 2.0);
  let topAdj: float = topVh -. ((cardHalfHeightPx *. 100.0) /. (parentElementHeightPx));
  // works, but not sure about order of compostion
  let transformA = "translate(" ++ f2s(cardHalfWidthPx) ++ "px, " ++ f2s(-.cardHalfWidthPx *. rotationOriginYOffsetMultiplier) ++ "px)";
  let transformB = "rotate(" ++ f2s(angleDeg *. (float_of_int(cardIndex) -. cardIndexOffset)) ++ "deg)";
  let transformC = "translate(" ++ f2s(-.cardHalfWidthPx) ++ "px, " ++ f2s(cardHalfWidthPx *. rotationOriginYOffsetMultiplier) ++ "px)";
  // position absolute is misleading/irrelevant, because we are using vw and vh units for left and top placement
  <img 
    src={filePath} 
    style=(
      ReactDOMRe.Style.make(
        ~height={f2s(cardHeightVh) ++ "vh"}, 
        ~position="absolute", 
        ~left={f2s(leftAdjustedVw) ++ "vw"}, 
        ~top={f2s(topAdj) ++ "vh"},
        ~transform={transformC ++ " " ++ transformB ++ " " ++ transformA},
        ()
      )
    )
  />
};
