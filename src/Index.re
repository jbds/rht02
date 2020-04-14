// redraw everything on browser window size change
[%%raw {| window.onresize = forceGlobalReRender |}];

let forceGlobalReRender = () => { 
  Js.log("ReRender whole window");
  ReactDOMRe.renderToElementWithId(<App />, "root");
};

// do one initial render 
forceGlobalReRender();

