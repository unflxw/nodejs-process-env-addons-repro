process.env.NODEJS_ENV_REPRO_BEFORE = "bar"

process.env = {...process.env}

process.env.NODEJS_ENV_REPRO = "foo"

console.log("Process environment:")
Object.entries(process.env).filter(([key, value]) =>
  key.startsWith("NODEJS_ENV_REPRO")
).forEach(([key, value]) => {
  console.log(`${key}=${value}`)
})

console.log("C binding environment:");
console.log(require("./lib/binding.js")());

console.log("Child process environment:");
require("child_process").spawn(
  "env | grep 'NODEJS_ENV_REPRO'",
  {shell: true, stdio: "inherit"})
