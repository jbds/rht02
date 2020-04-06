// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function f2s(prim) {
  return prim.toString();
}

function PlayingCardRotatable(Props) {
  var cardIndex = Props.cardIndex;
  var filePath = Props.filePath;
  var leftVw = Props.leftVw;
  var topVh = Props.topVh;
  var parentElementWidthPx = Props.parentElementWidthPx;
  var parentElementHeightPx = Props.parentElementHeightPx;
  var cardHalfWidthPx = parentElementHeightPx * 30.0 / (100.0 * 1.56 * 2.0);
  var leftAdjustedVw = leftVw * 0.8 - cardHalfWidthPx * 100.0 / parentElementWidthPx;
  var cardHalfHeightPx = parentElementHeightPx * 30.0 / (100.0 * 2.0);
  var topAdj = topVh - cardHalfHeightPx * 100.0 / parentElementHeightPx;
  var transformA = "translate(" + (cardHalfWidthPx.toString() + ("px, " + ((-cardHalfWidthPx * 4.25).toString() + "px)")));
  var transformB = "rotate(" + ((3.75 * (cardIndex - 0.0)).toString() + "deg)");
  var transformC = "translate(" + ((-cardHalfWidthPx).toString() + ("px, " + ((cardHalfWidthPx * 4.25).toString() + "px)")));
  return React.createElement("img", {
              style: {
                height: (30.0).toString() + "vh",
                left: leftAdjustedVw.toString() + "vw",
                position: "absolute",
                top: topAdj.toString() + "vh",
                transform: transformC + (" " + (transformB + (" " + transformA)))
              },
              src: filePath
            });
}

var cardHeightVh = 30.0;

var cardHeightOverCardWidth = 1.56;

var rotationOriginYOffsetMultiplier = 4.25;

var angleDeg = 3.75;

var cardIndexOffset = 0.0;

var baizeAsFractionOfViewportWidth = 0.8;

var make = PlayingCardRotatable;

exports.cardHeightVh = cardHeightVh;
exports.cardHeightOverCardWidth = cardHeightOverCardWidth;
exports.rotationOriginYOffsetMultiplier = rotationOriginYOffsetMultiplier;
exports.angleDeg = angleDeg;
exports.cardIndexOffset = cardIndexOffset;
exports.baizeAsFractionOfViewportWidth = baizeAsFractionOfViewportWidth;
exports.f2s = f2s;
exports.make = make;
/* react Not a pure module */
