
let ok_exn = fun
  | Ok(v) => v
  | Error(exn) => raise(exn)
;

module Make(Io: Aws_s3.Types.Io) {
  module S3 = Aws_s3.S3.Make(Io)
  module Credentials = Aws_s3.Credentials.Make(Io)
  open Io
  open Deferred

let run = (~bucket) => {
    let credentials = Credentials.Local.get_credentials(());
    let command = credentials >>= (result => {
        S3.ls(~credentials=ok_exn(result), ~bucket, ())
    });
    command >>| (fun
        | Ok((data, _)) => {
            List.iter(item => print_endline(item.S3.key), data)
        }
        | Error(error) => 
            switch(error) {
                | Redirect(_endpoint) => print_endline("redirect")
                | Not_found => print_endline("not found")
                | Failed(ex) => raise(ex)
                | Throttled => print_endline("throttled")
                | Unknown(_code, message) => print_endline(message)
            }
    )
}
}

module Aws = Make(Aws_s3_lwt.Io)

let foo = () => {
    let command = Aws.run(~bucket="jprice-dev")
    let () = Lwt_main.run(command)
};

