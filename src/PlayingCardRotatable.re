
[@react.component]
let make = 
  (
    ~cardIndex: int,
    ~filePath: string, 
    ~leftVw: float, 
    ~topVh: float, 
    ~parentElementWidthPx: float, 
    ~parentElementHeightPx: float,
    ~isFlipSide: bool,
    ~lifecycle: Ute.lifecycle
  ) 
=> 
{
  // set card size as % of vertical inner screen height
  let cardHeightVh = 25.0;
  // traditional aspect ratio is 1.56
  let cardHeightOverCardWidth = 1.56;
  // where is this from?
  let rotationOriginYOffsetMultiplier = 4.25;
  let angleDeg = 3.625;
  // use 6.0 for centre card upright, 8.o looks better, 
  // but offsets cards to left approx 5% of window width
  let cardIndexOffset =8.0;
  let baizeAsFractionOfViewportWidth = 0.8;
  let f2s = Js.Float.toString;
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
  // decide whether to show upside or flipside
  let adjustedFilePath = isFlipSide ? "./images/1B.svg" : filePath;
  // position absolute is misleading/irrelevant, because we are using vw and vh units for left and top placement
  let i =
  <img 
    src={adjustedFilePath} 
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
  />;
  // ReasonReact.null is the render 'no op'
  lifecycle == Hand ? i : ReasonReact.null;
};
