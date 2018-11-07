# aws-test


[![CircleCI](https://circleci.com/gh/yourgithubhandle/aws-test/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/aws-test/tree/master)


**Contains the following libraries and executables:**

```
aws-test@0.0.0
│
├─test/
│   name:    TestAwsTest.exe
│   main:    TestAwsTest
│   require: aws-test.lib
│
├─library/
│   library name: aws-test.lib
│   namespace:    AwsTest
│   require:
│
└─executable/
    name:    AwsTestApp.exe
    main:    AwsTestApp
    require: aws-test.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x AwsTestApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
