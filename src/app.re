type state = {
  count: int
};

type action = 
  | Increment
  | Decrement;

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => {
    count: 0
  },
  reducer: (action, {count}) =>
    switch action {
    | Increment => ReasonReact.Update({count: count + 1})
    | Decrement => ReasonReact.Update({count: count - 1})
    },
  render: ({state: {count}, reduce}) => {
    <div className="container">
      <h1>(ReasonReact.stringToElement("Reason Counter"))</h1>
      <div className="buttons">
        <button onClick=(reduce((_evt) => Increment)) className="btn btn-warning">(ReasonReact.stringToElement("+"))</button>
        <h2>(ReasonReact.stringToElement(string_of_int(count)))</h2>
        <button onClick=(reduce((_evt) => Decrement)) className="btn btn-warning">(ReasonReact.stringToElement("-"))</button>
      </div>
    </div>
  }
};
